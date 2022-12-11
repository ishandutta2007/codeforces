#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
int SG[max_n];
inline void init()
{
	SG[0]=0;
	for(int i=1;i<=200;++i)
	{
		set<int> S;
		for(int j=0;j<=i-2;++j)
			S.insert(SG[j]^SG[i-2-j]);
		for(int j=0;;++j)
		{
			if(S.find(j)==S.end())
			{
				SG[i]=j;
				break;
			}
		}
	}
	for(int i=201;i<=5e5;++i)
		SG[i]=SG[i-34];
}
char s[max_n];
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		int cntA=0,cntB=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='R')
				++cntA;
			else
				++cntB;
		}
		if(cntA!=cntB)
		{
			puts(cntA>cntB?"Alice":"Bob");
			continue;
		}
		int res=0;
		for(int i=1;i<=n;++i)
		{
			int j=i;
			while(j+1<=n&&s[j]!=s[j+1])
				++j;
			res^=SG[j-i+1];
			i=j;
		}
		puts(res?"Alice":"Bob");
	}
	return 0;
}