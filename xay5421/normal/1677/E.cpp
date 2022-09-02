#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005,maxQ=1000005;
int n,Q,p[N],ip[N],ll[N],rr[N],st[N],top;
vector<pair<int,int> >ve[N];
vector<tuple<int,int,int> >mods[N];
vector<tuple<int,int,int> >qs[N];
LL ans[maxQ];
struct mat{
	int a00,a01;
	LL a02;
	int a10,a11;
	LL a12;
	LL a22;
	mat operator*(const mat&rhs)const{
		mat ret;
		ret.a00=a00*rhs.a00+a01*rhs.a10;
		ret.a01=a00*rhs.a01+a01*rhs.a11;
		ret.a02=a00*rhs.a02+a01*rhs.a12+a02*rhs.a22;
		ret.a10=a10*rhs.a00+a11*rhs.a10;
		ret.a11=a10*rhs.a01+a11*rhs.a11;
		ret.a12=a10*rhs.a02+a11*rhs.a12+a12*rhs.a22;
		ret.a22=a22*rhs.a22;
		return ret;
	}
}tg[N*4];
bool hav[N*4];
struct vec{
	int a0,a1;
	LL a2;
	vec operator*(const mat&rhs)const{
		vec ret;
		ret.a0=a0*rhs.a00+a1*rhs.a10;
		ret.a1=a0*rhs.a01+a1*rhs.a11;
		ret.a2=a0*rhs.a02+a1*rhs.a12+a2*rhs.a22;
		return ret;
	}
	vec operator+(const vec&rhs)const{
		vec ret;
		ret.a0=a0+rhs.a0;
		ret.a1=a1+rhs.a1;
		ret.a2=a2+rhs.a2;
		return ret;
	}
}tr[N*4];
void pst(int k1,const mat&k2){
	tr[k1]=tr[k1]*k2;
	if(hav[k1])tg[k1]=tg[k1]*k2;
	else hav[k1]=1,tg[k1]=k2;
}
void psd(int k1){
	if(hav[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		hav[k1]=0;
	}
}
void upd(int k1){
	tr[k1]=tr[k1*2]+tr[k1*2+1];
}
void bud(int k1,int k2,int k3){
	hav[k1]=0;
	if(k2==k3){
		tr[k1]=(vec){1,0,0};
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4,int k5,const mat&k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
LL ss;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){ss+=tr[k1].a2;return;}
	psd(k1);
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
}
mat gen(int x){
	return (mat){1,x,0,0,1,0,1};
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(p[i]),ip[p[i]]=i;
	rep(i,1,n){
		while(top&&p[i]>p[st[top]])rr[st[top--]]=i-1;
		st[++top]=i;
	}
	while(top)rr[st[top--]]=n;
	per(i,n,1){
		while(top&&p[i]>p[st[top]])ll[st[top--]]=i+1;
		st[++top]=i;
	}
	while(top)ll[st[top--]]=1;
	rep(i,1,n)rep(j,1,n/i)if(i<j){
		int p1=ip[i],p2=ip[j];
		int p3=ip[i*j];
		if(p1>=ll[p3]&&p1<=rr[p3]&&p2>=ll[p3]&&p2<=rr[p3]){
			if(p2<p1)swap(p1,p2);
			ve[p3].eb(min(p1,p3),max(p2,p3));
		}
	}
	rep(i,1,n)if(!ve[i].empty()){
		sort(ve[i].begin(),ve[i].end());
		{
			vector<pair<int,int> >nve;
			each(x,ve[i]){
				while(!nve.empty()&&x.second<nve.back().second)nve.pop_back();
				nve.pb(x);
			}
			ve[i]=move(nve);
		}
		int last=ll[i]-1;
		each(x,ve[i]){
			// [last+1,x.first] [x.second,rr[i]]
			//assert(x.first>=last+1);
			if(x.first>=last+1){
				mods[last+1].eb(x.second,rr[i],1);
				mods[x.first+1].eb(x.second,rr[i],-1);
				//D("[%d,%d] [%d,%d]\n",last+1,x.first,x.second,rr[i]);
				last=x.first;
			}
		}
	}
	rep(tc,1,Q){
		int l,r;
		rd(l),rd(r);
		qs[l-1].eb(l,r,-tc);
		qs[r].eb(l,r,tc);
	}
	bud(1,1,n);
	rep(i,1,n){
		each(x,mods[i]){
			mdf(1,1,n,get<0>(x),get<1>(x),gen(get<2>(x)));
		}
		mdf(1,1,n,1,n,(mat){1,0,0,0,1,1,1});
		each(x,qs[i]){
			if(get<2>(x)>0){
				ss=0;
				ask(1,1,n,get<0>(x),get<1>(x));
				ans[get<2>(x)]+=ss;
			}else{
				ss=0;
				ask(1,1,n,get<0>(x),get<1>(x));
				ans[-get<2>(x)]-=ss;
			}
		}
	}
	rep(tc,1,Q)pt(ans[tc],'\n');
	return 0;
}