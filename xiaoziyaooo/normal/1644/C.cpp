#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,x,T;
int a[maxn];
long long mx[maxn],sum[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=0;i<=n;i++)
			mx[i]=-1e18;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				mx[j-i+1]=max(mx[j-i+1],sum[j]-sum[i-1]);
		mx[0]=0;
		for(int i=n-1;i>=0;i--)
			mx[i]=max(mx[i],mx[i+1]);
		long long ans=0;
		for(int i=0;i<=n;i++){
			ans=max(ans,mx[i]+1ll*i*x);
			printf("%lld%c",ans,i==n? '\n':' ');
		}
	}
	return 0;
}