#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define re(i,a,b) for (int i=a;i<b;++i)
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
const int N=1111111;
pii a[N];int n,f[N],ans;int T[N],b[N],cnt;
map<int,int> to;
void update(int x,int f) {for(int i=x;i<=1000000;i+=i&(-i))T[i]=max(T[i],f);}
int ask(int x) {int an=0;for (int i=x;i;i-=i&(-i))an=max(T[i],an);return an;}
int main() {
	read(n);rep(i,1,n)read(a[i].X,a[i].Y),b[++cnt]=a[i].X+a[i].Y,b[++cnt]=a[i].X-a[i].Y;
	sort(b+1,b+cnt+1);
	int len=unique(b+1,b+cnt+1)-b-1;
	rep(i,1,len)to[b[i]]=i;
	sort(a+1,a+n+1);
	rep(i,1,n){
		f[i]=ask(to[a[i].X-a[i].Y])+1;
		update(to[a[i].X+a[i].Y],f[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}