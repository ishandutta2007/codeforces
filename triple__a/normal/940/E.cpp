#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

const int maxn=100007;

struct queue{
	int num,val;
}q[maxn];

int a[maxn],mn[maxn];
LL s[maxn];
LL dp[maxn];
int n,m;

int main(){
	s[0]=dp[0]=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	int head=0,tail=1,cnt=1;
	while (cnt<=n){
		while(tail<=head&&a[cnt]<q[head].val){
			head--;
		}
		q[++head].num=cnt;
		q[head].val=a[cnt];
		while(tail<=head&&q[tail].num+m<=cnt){
			tail++;
		}
		mn[cnt]=q[tail].val;
		++cnt;
	}
	for (int i=1;i<=n;++i){
		if (i>=m){
			dp[i]=min(dp[i-1]+a[i],dp[i-m]+s[i]-s[i-m]-mn[i]);
		}
		else{
			dp[i]=s[i];
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}