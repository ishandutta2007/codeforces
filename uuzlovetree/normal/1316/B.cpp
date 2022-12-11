#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int T,n;
char str[maxn];
pair<string,int> s[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(str,0,sizeof(str));
		scanf("%d",&n);
		scanf("%s",str+1);
		for(int i=1;i<=n;++i)
		{
			string tmp;
			for(int j=i;j<=n;++j)tmp.push_back(str[j]);
			if((n&1)==(i&1))for(int j=i-1;j>=1;--j)tmp.push_back(str[j]);
			else for(int j=1;j<i;++j)tmp.push_back(str[j]);
			s[i]=make_pair(tmp,i);
		}
		sort(s+1,s+n+1);
		for(int i=1;i<=n;++i)str[i]=s[1].first[i-1];
		printf("%s\n",str+1);
		printf("%d\n",s[1].second);
	}
}