#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=200050;
char s[N];
int sol,odd;
int main()
{
	int n,a,b,i,j;
	scanf("%i %i %i",&n,&a,&b);
	scanf("%s",s+1);
	for(i=1;i<=n;i=j)
	{
		if(s[i]=='*') j=i+1;
		else
		{
			for(j=i;j<=n;j++) if(s[j]!=s[i]) break;
			int sz=j-i;
			if(sz&1) odd++;
			sol+=min(sz/2,a);a-=min(sz/2,a);
			sol+=min(sz/2,b);b-=min(sz/2,b);
		}
	}
	while(a && odd) a--,sol++,odd--;
	while(b && odd) b--,sol++,odd--;
	printf("%i\n",sol);
	return 0;
}