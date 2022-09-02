// author: xay5421
// created: Sun May 16 21:28:37 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,M=N*40;
int n,Q,rt,ind,lim=(1<<20)-1,ch[M][2],tg[M],andv[M],orv[M],sz[M];
void upd(int k1){
	andv[k1]=andv[ch[k1][0]]&andv[ch[k1][1]];
	orv[k1]=orv[ch[k1][0]]|orv[ch[k1][1]];
	sz[k1]=sz[ch[k1][0]]+sz[ch[k1][1]];
}
void ins(int&k1,int dep,int x){
	if(!k1)k1=++ind;
	if(dep==-1){
		andv[k1]=x;
		orv[k1]=x;
		sz[k1]=1;
		return;
	}
	ins(ch[k1][x>>dep&1],dep-1,x);
	upd(k1);
}
void _xor(int k1,int dep,int x){
	if(dep!=-1){
		if(x>>dep&1)swap(ch[k1][0],ch[k1][1]);
	}
	int _a=andv[k1],_o=orv[k1];
	andv[k1]=((lim^_o)&x)|(_a&(lim^x));
	orv[k1]=(_o&(lim^x))|((lim^_a)&x);
	tg[k1]^=x;
}
void psd(int k1,int dep){
	if(tg[k1]){
		if(ch[k1][0])_xor(ch[k1][0],dep-1,tg[k1]);
		if(ch[k1][1])_xor(ch[k1][1],dep-1,tg[k1]);
		tg[k1]=0;
	}
}
void mer(int&k1,int k2,int dep){
	if(!k1){k1=k2;return;}
	if(!k2)return;
	if(dep==-1)return;
	psd(k1,dep),psd(k2,dep);
	mer(ch[k1][0],ch[k2][0],dep-1);
	mer(ch[k1][1],ch[k2][1],dep-1);
	upd(k1);
}
void _or(int k1,int dep,int x){
	if(dep==-1)return;
	int tmp=(lim^andv[k1])&x;
	if((tmp&orv[k1])==0){
		_xor(k1,dep,tmp);
		return;
	}
	psd(k1,dep);
	if(x>>dep&1){
		_xor(ch[k1][0],dep-1,1<<dep);
		mer(ch[k1][1],ch[k1][0],dep-1);
		ch[k1][0]=0;
		_or(ch[k1][1],dep-1,x);
	}else{
		_or(ch[k1][0],dep-1,x);
		_or(ch[k1][1],dep-1,x);
	}
	upd(k1);
}
int qry(int k1,int dep,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return 0;
	if(k4<=k2&&k3<=k5){
		return sz[k1];
	}
	psd(k1,dep);
	int mid=(k2+k3)>>1;
	return qry(ch[k1][0],dep-1,k2,mid,k4,k5)+qry(ch[k1][1],dep-1,mid+1,k3,k4,k5);
}
void split(int&k1,int&k2,int dep,int l,int r,int lx,int rx){
	if(k1==0||l>rx||r<lx){
		k2=0;
		return;
	}
	if(lx<=l&&r<=rx){
		k2=k1,k1=0;
		return;
	}
	psd(k1,dep),k2=++ind;
	int mid=(l+r)>>1;
	split(ch[k1][0],ch[k2][0],dep-1,l,mid,lx,rx);
	split(ch[k1][1],ch[k2][1],dep-1,mid+1,r,lx,rx);
	upd(k1),upd(k2);
}
void out(int k1,int dep,int l,int r){
	if(!k1)return;
	if(l==r){
		D("{%d %d %d}",l,andv[k1],orv[k1]);
		return;
	}
	psd(k1,dep);
	int mid=(l+r)>>1;
	out(ch[k1][0],dep-1,l,mid);
	out(ch[k1][1],dep-1,mid+1,r);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	andv[0]=lim;
	rd(n),rd(Q);
	rep(i,1,n){
		int x;
		rd(x);
		ins(rt,19,x);
	}
	_xor(rt,19,lim);
	_xor(rt,19,lim);
	//out(rt,19,0,lim),D("\n");
	rep(i,1,Q){
		int t;
		rd(t);
		if(t==4){
			int l,r;
			rd(l),rd(r);
			pt(qry(rt,19,0,lim,l,r),'\n');
			continue;
		}
		int l,r,x;
		rd(l),rd(r),rd(x);
		int now=0;
		split(rt,now,19,0,lim,l,r);
		//out(now,19,0,lim),D("\n");
		if(t==1){
			_xor(now,19,lim);
			//D("1:"),out(now,19,0,lim),D("\n");
			_or(now,19,lim^x);
			//D("2:"),out(now,19,0,lim),D("\n");
			_xor(now,19,lim);
			//D("3:"),out(now,19,0,lim),D("\n");
		}else if(t==2){
			_or(now,19,x);
		}else{
			_xor(now,19,x);
		}
		//out(now,19,0,lim),D("\n");
		//out(rt,19,0,lim),D("\n");
		mer(rt,now,19);
		//out(rt,19,0,lim),D("\n");
	}
	return 0;
}