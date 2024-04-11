#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string str[440];

int sum[440][440];

int ok[26];

long long ans=0;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N,M,K;
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>str[i];
		str[i]=' '+str[i];
	}
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++) if(str[i][j]=='a') sum[i][j]=1;
	}
	for(int i=0;i<=N;i++)
	{
		for(int j=1;j<=M;j++) sum[i][j]+=sum[i][j-1];
	}
	for(int j=0;j<=M;j++)
	{
		for(int i=1;i<=N;i++) sum[i][j]+=sum[i-1][j];
	}
	for(int x1=1;x1<=N;x1++)
	{
		for(int x2=x1+1;x2<=N;x2++)
		{
			memset(ok,0,sizeof(ok));
			int s=1,t=1;
			while(s<=M)
			{
				while(t<=M)
				{
					if(sum[x2][t]-sum[x2][s-1]-sum[x1-1][t]+sum[x1-1][s-1]>K) break;
					if(str[x1][t]!=str[x2][t]){t++; continue;}
					ok[str[x1][t]-'a']++;
					t++;
				}
				if(str[x1][s]==str[x2][s])
				{
					if(t>s+1) ans+=(ok[str[x1][s]-'a']-1);
					ok[str[x1][s]-'a']--;
				}
				s++;
			}
		}
	}
	//printf("%d\n",ans);
	cout<<ans<<"\n";
	return 0;
}