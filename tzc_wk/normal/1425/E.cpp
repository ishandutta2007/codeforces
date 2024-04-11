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
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=1e5+5;
int n,k,a[MAXN],b[MAXN];
ll x[MAXN],mx[MAXN],pmx[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	if(k==0){
		ll sum=0,ans=0;
		for(int i=n;i;i--){
			sum+=a[i];ans=max(ans,sum-b[i]);
		} printf("%lld\n",ans);
	} else if(k==1){
		ll sum=0,ans=0;int mn=0x3f3f3f3f;
		for(int i=n;i;i--){sum+=a[i];x[i]=sum-b[i];}
		sum=0;
		for(int i=n;i;i--) mx[i]=max(mx[i+1],x[i]);
		for(int i=1;i<=n;i++) pmx[i]=max(pmx[i-1],x[i]);
		for(int i=1;i<n;i++){
			mn=min(mn,b[i]);sum+=a[i];
			ans=max(ans,sum-mn+mx[i+1]);
		}
		for(int i=1;i<n-1;i++){
			ans=max(ans,mx[i+1]);
			ans=max(ans,pmx[i]-min(a[i+1],b[i+1]));
		}
		printf("%lld\n",ans);
	} else{
		ll sum=0,ans=0;
		for(int i=n;i;i--){
			sum+=a[i];ans=max(ans,sum-b[i]);
		}
		sum=0;int mn=0x3f3f3f3f;
		for(int i=1;i<n;i++) mn=min(mn,b[i]),sum+=a[i];
		sum+=a[n];ans=max(ans,max(sum-mn,0ll));
		printf("%lld\n",ans);
	}
	return 0;
}