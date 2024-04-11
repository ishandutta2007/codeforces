%:pragma GCC optimize(4)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<new>
#include<map>
using namespace std;
#define N 2000001
int ne[N];
char s[2000001];
char t[2000001];
int n,m;
int it[2000001];
//int x,pre;
int x[2000001];
int S[N];
long long ans=1;
const long long mod=1e9+7;
bool can[N];
int main()
{
	scanf("%d%d",&n,&m);
	if(n==20)
	{
//		puts("0");return 0;
	}
	scanf("%s",t);
	int wei=0;
	int len=strlen(t);
	for(int i=1;i<len;i++)
	{
		while(t[i]!=t[wei]&&wei)wei=ne[wei-1];
		if(t[i]==t[wei])wei++;
		ne[i]=wei;
	}
	int k=len-1;
	while(k)
	{
		if(ne[k-1])
		can[ne[k-1]]=1;
		k=ne[k-1];
	}
	if(t[len-1]==t[0])can[0]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x[i]);
		if(x[i]+len-1>n) {puts("0");return 0;}
		if(i==1) continue;
		if((x[i]-x[i-1])>=len) continue;
		else
		{
			int k=len-(x[i]-x[i-1]);
			if(!can[k-1])
			{
				puts("0");return 0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		S[x[i]]=len;
	}
	for(int i=1;i<=n;i++)
	{
		if(S[i]==0)
		{
			ans*=26;
			ans=ans%mod;
		}
		S[i+1]=max(S[i]-1,S[i+1]);
	}
	cout<<ans;
//	puts("");cout<<ne[2];
}