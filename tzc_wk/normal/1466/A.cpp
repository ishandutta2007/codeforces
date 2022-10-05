#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=50;
int n,a[MAXN+5],hav[MAXN];
void solve(){
	scanf("%d",&n);fill0(hav);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) if(!hav[a[i]-a[j]]) ans++,hav[a[i]-a[j]]=1;
	printf("%d\n",ans);
}
int main(){
	int T;scanf("%d",&T);while(T--) solve();
	return 0;
}