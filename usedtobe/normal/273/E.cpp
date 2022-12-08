#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define Re(i,x) for (i=x.begin();i!=x.end();++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(i,a) for (int i=0;i<(int)a;++i)
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define POSIN(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
#define clr(x) memset(x,0,sizeof x)
#define SZ(x) ((int)x.size())
#define TWO(x) (1<<(x))
#define mp make_pair
#define pb push_back
#define mod 1000000007
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
struct Sg{
	int l,r,sg;
	Sg(){}
	Sg(int _l,int _r,int _sg) {l=_l,r=_r,sg=_sg;}
} a[105];
int ex(int x,int y) {if(x!=0&&y!=0)return 0;if(x!=1&&y!=1)return 1;return 2;}
int n,p,m;
ll work(int l,int r) {return (l+r)*1ll*(r-l+1)/2;}
void add(ll &x,ll y){x+=y;x%=mod;}
ll c[4],ans[1005][4];
int main() {
	read(n,p);a[0]=(Sg){1,2,0};int la=2;
	while(la<p) {
		int L,R;L=la+1;
		int u=L/3,v=L-L/3;
		int i,j;
		for(i=0;i<=m;++i)if(a[i].l<=u&&a[i].r>=u)break;
		for(j=0;j<=m;++j)if(a[j].l<=v&&a[j].r>=v)break;
		int ll=L,rr=p;
		while (ll<rr) {
			int mm=(ll+rr+1)>>1;
			if (mm/3>a[i].r||mm-mm/3>a[j].r) rr=mm-1;
			else ll=mm;
		}
		R=ll;
		a[++m]=(Sg){L,R,ex(a[i].sg,a[j].sg)};
		if (m>1&&a[m].sg==a[m-1].sg) a[m-1].r=a[m].r,--m;
		la=R;
	}
	rep(i,0,m)add(c[a[i].sg],work(p-a[i].r,p-a[i].l));ans[0][0]=1;
	rep(i,0,n-1)rep(j,0,3)rep(k,0,2)add(ans[i+1][j^k],ans[i][j]*c[k]%mod);
    cout<<(ans[n][1]+ans[n][2]+ans[n][3])%mod<<endl;
	return 0;
}