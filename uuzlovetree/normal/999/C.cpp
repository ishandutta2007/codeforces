#include<bits/stdc++.h>
#define ll long long
#define maxn 400005
using namespace std;
int n,k;
bool vis[maxn];
char s[maxn];
int num[30],head[30],nxt[maxn],p[30];
int main()
{
	cin>>n>>k;
	scanf("%s",s+1);
	for(int i=n;i;--i)
	{
		num[s[i]-'a'+1]++;
		nxt[i]=head[s[i]-'a'+1];
		head[s[i]-'a'+1]=i;
	}
	for(int i=1;i<=26;++i)p[i]=head[i];
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=26;++j)
		{
			if(num[j])
			{
				vis[p[j]]=1;num[j]--;
				p[j]=nxt[p[j]];
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)if(!vis[i])printf("%c",s[i]);
	return 0;
}