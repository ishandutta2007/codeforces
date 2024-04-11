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
ll ans;
int n,a,b,S;
int c[20005];
bool check(ll m){
	int sum=m/a;
	For(i,0,S) c[i]=i+1;
	for (int i=1;1ll*i*b<=m&&sum<n;++i)
		for (int j=0;1ll*i*b+1ll*j*a<=m&&sum<n;j++)
			sum+=c[j],c[j]+=(j?c[j-1]:0); 
	return sum>=n;
}
void calc(ll m){
	int sum=m/a;
	ans+=1ll*sum*(sum+1)/2*a;
	For(i,0,S) c[i]=i+1;
	for (int i=1;1ll*i*b<=m;++i)
		for (int j=0;1ll*i*b+1ll*j*a<=m;j++){
			ans+=1ll*c[j]*(1ll*i*b+1ll*j*a);
			sum+=c[j],c[j]+=(j?c[j-1]:0);
		}
	//cout<<ans<<' '<<sum<<' '<<m<<endl;
	ans-=m*(sum-n);
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if (a>b) swap(a,b);
	n--; ans=1ll*n*(a+b);
	n--; S=sqrt(n*2)+1;
	if (!a) return printf("%lld\n",ans),0;
	ll l=0,r=1ll*n*a,p;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)) p=mid,r=mid-1;
		else l=mid+1;
	}
	calc(p);
	printf("%lld\n",ans);
}