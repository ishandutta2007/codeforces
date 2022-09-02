#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int N=1000005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,m,p,a[N];
LL sum[N*4];
vector<LL>v[N*4];
void upd(int k1,int sz){
	sum[k1]=sum[k1*2]+sum[k1*2+1];
	int lsz=(sz+1)>>1;
	int rsz=sz>>1;
	v[k1].assign(sz+2,INFLL);
	int j=0;
	rep(i,0,lsz){
		if(j>rsz)--j;
		for(;j<=rsz;++j){
			LL tem=v[k1*2+1][j]+1LL*i*p-sum[k1*2];
			LL w=v[k1*2][i+1]-1-1LL*i*p+sum[k1*2];
			if(w<v[k1*2+1][j]){
				if(j)--j;
				break;
			}
			v[k1][i+j]=min(v[k1][i+j],max(v[k1*2][i],tem));
		}
	}
}
void bud(int k1,int k2,int k3){
	D("bud %d %d %d\n",k1,k2,k3);
	if(k2==k3){
		v[k1].PB(~INFLL);
		v[k1].PB(p-a[k2]);
		v[k1].PB(INFLL);
		sum[k1]=a[k2];
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1,k3-k2+1);
}
LL qry(int k1,int k2,int k3,int k4,int k5,LL k6){
	D("qry %d\n",k1);
	if(k2>k5||k3<k4)return k6;
	if(k4<=k2&&k3<=k5){
		LL pos=upper_bound(v[k1].begin(),v[k1].end(),k6)-v[k1].begin()-1;
		return k6-p*pos+sum[k1];
	}
	int mid=(k2+k3)>>1;
	return qry(k1*2+1,mid+1,k3,k4,k5,qry(k1*2,k2,mid,k4,k5,k6));
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),rd(p);
	rep(i,1,n)rd(a[i]);
	bud(1,1,n);
	rep(i,1,m){
		int l,r;
		rd(l),rd(r);
		pt(qry(1,1,n,l,r,0),'\n');
	}
	return 0;
}