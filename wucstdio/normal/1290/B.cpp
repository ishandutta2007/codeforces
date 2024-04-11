#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,cnt[26][200005];
char s[200005];
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)cnt[j][i]=cnt[j][i-1];
		cnt[s[i]-'a'][i]++;
	}
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int num=0;
		for(int i=0;i<26;i++)
		  if(cnt[i][r]!=cnt[i][l-1])
		    num++;
		if(num>=3||s[l]!=s[r]||l==r)puts("Yes");
		else puts("No");
	}
	return 0;
}