#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
int n,p[N],fl[N],a[N];
ll s[N];
bool check(ll S){
	For(i,1,n) s[i]=0;
	Rep(i,n,1){
		s[i]-=a[i];
		if (!fl[i]) s[i]+=S;
		s[i]=min(s[i],1ll<<61);
		if (s[i]<0) return 0;
		s[p[i]]=min(1ll<<61,s[p[i]]+s[i]);
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	For(i,2,n) scanf("%d",&p[i]);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) fl[p[i]]=1;
	ll l=0,r=1ll<<50,ans=-1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)) 
			ans=mid,r=mid-1;
		else l=mid+1;
	} 
	cout<<ans<<endl;
}