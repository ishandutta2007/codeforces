#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;
const int MAXN=10000+10;
int n,q;
char s[MAXN][10],t[10];
map <long long,int> list,flag;

namespace Hsh_Set
{
	typedef long long ll;
	const ll BASE=9973;
	const int N=10;
	
	ll hsh(char *A,int len)
	{
		ll re=0;
		for(int i=1;i<=len;i++) re=re*BASE+A[i];
		return re;
	}
}
using namespace Hsh_Set;

int main()
{
	//freopen("out.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		int len=strlen(s[i]+1);
		for(int j=1;j<=len;j++)
			for(int k=j;k<=len;k++)
				{
					ll sub=hsh(s[i]+j-1,k-j+1);
					if(flag[sub]!=i) 
					{
						++list[sub];
						flag[sub]=i;
					}
				}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",t+1);
		ll temp=hsh(t,strlen(t+1));
		printf("%d %s\n",list[temp],list[temp] ? s[flag[temp]]+1 : "-");
	}
	return 0;
}