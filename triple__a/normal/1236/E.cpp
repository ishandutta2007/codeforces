#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=500007;

int n,m;
int a[maxn],cnt[maxn<<2];
ll ans=0;

int main(){
	scanf("%d%d",&n,&m);
	if (n==1){
		if (m){
			printf("0");
		}
		else{
			printf("1");
		}
		return 0;
	}
	for (int i=1;i<=m;++i){
		scanf("%d",&a[i]);
	}
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;++i){
		cnt[i+maxn]=1;
	}
	for (int i=1;i<=m;++i){
		cnt[maxn+a[i]-i-1]+=cnt[maxn+a[i]-i];
		cnt[maxn+a[i]-i]=0;
	}
	int sum=0;
	for (int i=maxn+n-m-1;i<=maxn+n;++i){
		sum+=cnt[i];
	}
	ans=1LL*sum*n;
	for (int i=1;i<n;++i){
		ans+=1LL*cnt[maxn+i-m-1]*i;
	}
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;++i){
		cnt[i]=1;
	}
	for (int i=1;i<=m;++i){
		cnt[a[i]+i+1]+=cnt[a[i]+i];
		cnt[a[i]+i]=0;
	}
	for (int i=2;i<=n;++i){
		ans-=1LL*cnt[i+m+1]*(i-1);
	}
	printf("%I64d\n",ans);
	return 0;
}