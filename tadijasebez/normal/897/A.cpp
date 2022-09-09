#include <stdio.h>
#include <cstring>
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=100050;
const int inf=1e9+69;
int sol;
char ch[N];
int main()
{
	int n,m,i,l,r;
	char c1,c2;
	scanf("%i %i",&n,&m);
	scanf("%s",ch+1);
	while(m--)
	{
		scanf("%i %i %c %c",&l,&r,&c1,&c2);
		for(i=l;i<=r;i++)
		{
			if(ch[i]==c1) ch[i]=c2;
		}
	}
	for(i=1;i<=n;i++) printf("%c",ch[i]);
	return 0;
}