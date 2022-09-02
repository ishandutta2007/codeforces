// author: xay5421
// created: Wed Sep  1 09:00:28 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,Q,s[N],m[N],r[N],T;
LL res;
struct seg{
	int l,r,t;
	bool operator<(const seg&k)const{return r<k.r;}
};
set<seg>S;
void brute(int pos){
	res+=min((LL)m[pos],1LL*T*r[pos]+s[pos]);
	if(r[pos]==0)m[pos]=0;
}
set<seg>::iterator split(int r){
	auto it=S.lower_bound((seg){r,r,0});
	if(it==S.end())return S.end();
	if(it->l>r)return it;
	if(it->r==r)return next(it);
	auto cur=*it;
	S.erase(it);
	S.insert((seg){cur.l,r,cur.t});
	return S.insert((seg){r+1,cur.r,cur.t}).first;
}
int xay_div(int a,int b){
	if(!b)return N-1;
	return a/b;
}
const int M=N*40;
int rt[N],ind,lc[M],rc[M],cnt[M];
LL sum1[M],sum2[M];
void ins(int&k1,int k,int k2,int k3,int k4,int k5,int k6){
	k1=++ind,lc[k1]=lc[k],rc[k1]=rc[k];
	sum1[k1]=sum1[k]+k5,sum2[k1]=sum2[k]+k6;
	if(k2==k3)return;
	int mid=(k2+k3)>>1;
	if(k4<=mid){
		ins(lc[k1],lc[k],k2,mid,k4,k5,k6);
	}else{
		ins(rc[k1],rc[k],mid+1,k3,k4,k5,k6);
	}
}
LL s1,s2;
void ask1(int k1,int k,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		s1+=sum1[k1]-sum1[k];
		return;
	}
	int mid=(k2+k3)>>1;
	ask1(lc[k1],lc[k],k2,mid,k4,k5),ask1(rc[k1],rc[k],mid+1,k3,k4,k5);
}
void ask2(int k1,int k,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		s2+=sum2[k1]-sum2[k];
		return;
	}
	int mid=(k2+k3)>>1;
	ask2(lc[k1],lc[k],k2,mid,k4,k5),ask2(rc[k1],rc[k],mid+1,k3,k4,k5);
}
void sol(int l,int r,int oldT){
	D("sol %d %d %d\n",l,r,oldT);
	s1=0;
	ask1(rt[r],rt[l-1],0,N-1,min(T-oldT,100001),N-1);
	res+=s1*(T-oldT);
	s2=0;
	if(T-oldT-1>=0)ask2(rt[r],rt[l-1],0,N-1,0,min(T-oldT,100001)-1);
	res+=s2;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(s[i]),rd(m[i]),rd(r[i]);
	rep(i,1,n){
		ins(rt[i],rt[i-1],0,N-1,xay_div(m[i],r[i]),r[i],m[i]);
	}
	rd(Q);
	set<int>I;
	rep(i,1,n)I.insert(i);
	rep(_,1,Q){
		int l,r;
		rd(T),rd(l),rd(r);
		res=0;
		for(auto it=I.lower_bound(l);it!=I.end()&&*it<=r;){
			brute(*it);
			I.erase(it++);
		}
		if(_==2){
			D("!\n");
		}
		auto ends=split(r),begs=split(l-1);
		for(auto it=begs;it!=ends;){
			sol(it->l,it->r,it->t);
			S.erase(it++);
		}
		pt(res,'\n');
		S.insert((seg){l,r,T});
		/*for(auto it=S.begin();it!=S.end();++it){
			if(it!=S.begin())assert(it->l>prev(it)->r);
		}
		for(auto it:S)D("{%d %d %d}",it.l,it.r,it.t);
		D("\n");*/
	}
	return 0;
}