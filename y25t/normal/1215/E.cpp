#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 400005

int n,a[N];

ll f[25][25],dp[(1<<20)+5];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=20;i++)
		for(int j=0;j<=20;j++){
			int cnt=0;
			for(int k=1;k<=n;k++)
				if(a[k]==i)
					f[i][j]+=cnt;
				else if(!j||a[k]==j)
					cnt++;
		}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int x=0;x<(1<<20);x++)
		for(int i=1;i<=20;i++)
			if(!(x&(1<<(i-1)))){
				ll tmp=f[i][0];
				for(int j=1;j<=20;j++)
					if(x&(1<<(j-1)))
						tmp-=f[i][j];
				dp[x|(1<<(i-1))]=std::min(dp[x|(1<<i-1)],dp[x]+tmp);
			}
	printf("%I64d",dp[(1<<20)-1]);
}