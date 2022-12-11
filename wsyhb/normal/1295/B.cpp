#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,T=2e5+5,q=1e5;
char s[N];
int b[N],cnt[T];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d%d%s",&n,&x,s+1);
		memset(b,0,sizeof(b));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			b[i]=b[i-1]+(s[i]=='0'?1:-1);
			cnt[b[i]+q]++;
		}
		if(!b[n])
		{
			if(x>=-1e5&&x<=1e5&&cnt[x+q]) printf("-1\n");
			else if(!x) printf("1\n");
			else printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=0;i<=2e5;i++)
			if((x-(i-q))%b[n]==0&&(x-(i-q))/b[n]>=0) ans+=cnt[i];
		if(!x) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
//1 0 1 2 1 2