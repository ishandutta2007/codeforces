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
const int MAXN=100;
const int INF=0x3f3f3f3f;
int n,a[MAXN+5];ll k,ans=0;
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),k+=a[i],a[i]--;
	for(int l=1,r;;l=r+1){
		r=INF;ll sum=n;
		for(int i=1;i<=n;i++) if((a[i]/l)!=0) chkmin(r,a[i]/(a[i]/l));
		if(r==INF){
			if(l<=k/n) chkmax(ans,k/n);
			break;
		} for(int i=1;i<=n;i++) sum+=a[i]/l;
		if(sum<=k/r) chkmax(ans,r);
		else if(sum<=k/l) chkmax(ans,k/sum);
	} printf("%lld\n",ans);
	return 0;
}