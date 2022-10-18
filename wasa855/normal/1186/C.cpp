#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 1000005
char a[N],b[N];
int sum[N];
int main()
{
	scanf("%s\n",a+1);
	scanf("%s",b+1);
	int n=strlen(a+1),m=strlen(b+1);
	int sb=0;
	for(int i=1;i<=m;i++)
	{
		if(b[i]=='1') sb++;
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i]-'0';
	}
	int ans=0;
//	if((sa+sb)%2==0) ans++;
//	printf("%d %d\n",sa,sb);
	for(int i=1;i<=n;i++)
	{
		int to=i+m-1;
		if(to>n) break;
		if((sum[to]-sum[i-1]+sb)%2==0) ans++;
//		printf("%d %d\n",sa,sb);
	}
	cout<<ans<<endl;
	return 0;
}