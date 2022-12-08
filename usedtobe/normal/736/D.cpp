#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=2222,M=555555;
//head
int n,m,x[M],y[M];
bitset<N> a[N],b[N];
int main(){
	read(n,m);
	rep(i,1,m)read(x[i],y[i]),a[x[i]][y[i]]=1;
	rep(i,1,n)b[i][i]=1;
	rep(i,1,n){
		int ps=i;
		while(!a[ps][i])++ps;
		swap(a[ps],a[i]);
		swap(b[ps],b[i]);
		rep(j,1,n)if(i!=j&&a[j][i])a[j]^=a[i],b[j]^=b[i];
	}
	rep(i,1,m)puts(!b[y[i]][x[i]]?"YES":"NO");
	return 0;
}