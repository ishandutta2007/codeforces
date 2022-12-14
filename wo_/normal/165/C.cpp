#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int cnt[1001000];
char in[1001000];
int k;

int main()
{
	scanf("%d",&k);
	scanf("%s",in);
	memset(cnt,0,sizeof(cnt));
	int n=strlen(in);
	cnt[0]=0;
	for(int i=1;i<=n;i++)
	{
		cnt[i]=cnt[i-1]+(in[i-1]=='1'?1:0);
	}
	long long res=0;
	for(int i=0;i<n;i++)
	{
		int plus=upper_bound(cnt,cnt+n+1,cnt[i]+k)-max(cnt+i,lower_bound(cnt,cnt+n+1,cnt[i]+k));
		res+=(k==0?plus-1:plus);
	}
	for(int i=0;i<=n;i++)
	{
	//	printf("%d\n",cnt[i]);
	}
//	printf("%I64d\n",res);
	cout<<res;
	return 0;
}