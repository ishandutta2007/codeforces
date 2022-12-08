#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#include<vector>
#include<map>
#include<iostream>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(it,a) for (it=a.begin();it!=a.end();++it)
#define N 100005
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
int f[21][N],n,a[N],d[N];map<int,ll> ans;
int ask(int l,int r){int h=d[r-l+1];return __gcd(f[h][l],f[h][r-(1<<h)+1]);}
int find(int l,int r,int p,int x){
	while(l<r){int mid=(l+r)>>1;ask(p,mid)==x?l=mid+1:r=mid;}
	return l;
}	
int main() {
	read(n);rep(i,1,n)read(a[i]);rep(i,2,n)d[i]=d[i-1]+(i==(i&(-i)));
	rep(i,1,n)f[0][i]=a[i];
	rep(i,1,d[n])rep(j,1,n-(1<<i)+1)f[i][j]=__gcd(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	rep(i,1,n) {int x=a[i],now=i;while(now<=n){int a=find(now,n+1,i,x);ans[x]+=a-now;now=a,x=ask(i,now);}}
	int x,m;read(m);while (m--) read(x),cout<<ans[x]<<endl;
	return 0;
}