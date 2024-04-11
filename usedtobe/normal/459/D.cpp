#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define foreach(e,x) for (typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define INF 0x7fffffff
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
#define N 2000005
int n,a[N],b[N],pre[N],g[N],f[N],suf[N];
ll ans[N],c[N];
void add(int x,int de) {for(int i=x;i<=n;i+=i&(-i)) c[i]+=(ll)de;}
ll ask(int x) {ll ans=0;for (int i=x;i;i-=i&(-i)) ans+=c[i];return ans;}
int main() {
	read(n);rep(i,1,n)read(a[i]),b[i]=a[i];sort(b+1,b+n+1);
	int len=unique(b+1,b+n+1)-b-1;
	rep(i,1,n) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
	rep(i,1,n) {
		f[i]=f[pre[a[i]]]+1;
		pre[a[i]]=i;
	}
	dep(i,n,1) {
		g[i]=g[suf[a[i]]]+1;
		suf[a[i]]=i;
	}
	ll ans=0;
	dep(i,n-1,1) {
		int tmp=f[1];
		add(g[i+1],1);
		ans+=ask(f[i]-1);
	}
	cout<<ans<<endl;
	return 0;
}