#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
const int N=100050;
char s[3][N];
int cnt[52],ans[3];
int max(int a, int b){ return a>b?a:b;}
int val(char c)
{
	if(c<='z' && c>='a') return c-'a';
	return c-'A'+26;
}
int main()
{
	int n,i,m,j;
	scanf("%i",&n);
	for(j=0;j<3;j++)
	{
		scanf("%s",s[j]+1);
		int m=strlen(s[j]+1);
		for(i=0;i<52;i++) cnt[i]=0;
		for(i=1;i<=m;i++) cnt[val(s[j][i])]++;
		int Max=0;
		for(i=0;i<52;i++) Max=max(Max,cnt[i]);
		if(n<=m-Max) ans[j]=Max+n;
		else
		{
			if(n>1) ans[j]=m;
			else ans[j]=m-1;
		}
		/*{
			if((n&1)==((m-Max)&1)) ans[j]=m;
			else ans[j]=m-1;
		}*/
	}
	//if(ans[0]==ans[1] || ans[0]==ans[2] || ans[1]==ans[2]) return printf("Draw\n"),0;
	if(ans[0]>ans[1] && ans[0]>ans[2]) return printf("Kuro\n"),0;
	if(ans[1]>ans[0] && ans[1]>ans[2]) return printf("Shiro\n"),0;
	if(ans[2]>ans[0] && ans[2]>ans[1]) return printf("Katie\n"),0;
	printf("Draw\n");
	return 0;
}