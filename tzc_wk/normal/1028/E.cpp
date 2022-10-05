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
typedef long long ll;
const int MAXN=140582+5;
int n,a[MAXN],mx=0,v=0;ll b[MAXN];
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool flg=1;for(int i=2;i<=n;i++) flg&=(a[i]==a[1]);
	if(flg&&a[1]==0){puts("YES");for(int i=1;i<=n;i++) printf("1 ");printf("\n");return 0;} 
	if(flg) return puts("NO"),0;
	for(int i=1;i<=n;i++) (a[i]>mx)?(mx=a[i],v=i):0;
	while(a[v]==mx){v--;if(!v) v=n;}v++;if(v==n+1) v=1;
	ll x=0;for(int i=1;i<=n;i++){if(i==2) x+=mx;x+=a[v];b[v]=x;v--;if(!v) v=n;}
	puts("YES");for(int i=1;i<=n;i++) printf("%lld ",b[i]);
	return 0;
}