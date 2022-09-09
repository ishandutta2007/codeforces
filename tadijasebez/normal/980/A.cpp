#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=105;
char s[N];
int main()
{
	int n,i,x=0,y=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='o') x++;
		else y++;
	}
	if(x==0) printf("YES\n");
	else if(y%x==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}