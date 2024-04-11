#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
typedef long long LL;
const int N=100005,B=60;
int n,K;
LL sum[N];
vector<LL>a[N];
vector<LL>sol(int l,int r){
	if(l==r){
		vector<LL>res(K+1,0);
		rep(i,1,SZ(a[l])-1)res[i]=res[i-1]+a[l][i];
		return res;
	}
	int mid=(l+r)>>1;
	vector<LL>L(sol(l,mid)),R(sol(mid+1,r));
	rep(i,mid+1,r){
		int sz=SZ(a[i])-1;
		per(j,K,sz)L[j]=max(L[j],L[j-sz]+sum[i]);
	}
	rep(i,l,mid){
		int sz=SZ(a[i])-1;
		per(j,K,sz)R[j]=max(R[j],R[j-sz]+sum[i]);
	}
	vector<LL>cur(K+1,0);
	rep(i,0,K)cur[i]=max(L[i],R[i]);
	return cur;
}
int main(){
	rd(n),rd(K);
	rep(i,1,n){
		int m;
		rd(m);
		a[i].resize(m+1);
		rep(j,1,m)rd(a[i][j]);
		if(SZ(a[i])>K+1){
			a[i].resize(K+1);
		}
		rep(j,1,SZ(a[i])-1)sum[i]+=a[i][j];
	}
	vector<LL>f(sol(1,n));
	pt(f[K],'\n');
	return 0;
}