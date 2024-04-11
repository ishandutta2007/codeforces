#include<bits/stdc++.h>
using namespace std;
const int N = 100009;
#define ll long long
ll T,n,a[N],sum[N];
char s[N];
map<ll ,ll >mp;
int main(){
	scanf("%lld",&T);
	while(T--){
		mp.clear();
		scanf("%lld%s",&n,s);sum[0]=0;
		for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
		for(int i=1;i<=n;i++) a[i]-=1ll;
		mp[0]=1ll;ll ans=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
			ans+=mp[sum[i]];
			mp[sum[i]]++;
		}	
		printf("%lld\n",ans);
	}	
	return 0;
}