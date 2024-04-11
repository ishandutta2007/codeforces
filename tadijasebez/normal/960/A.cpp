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
const int N=1000050;
char s[N];
int main()
{
	int n,i,a=0,b=0,c=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]!='a') break;
		a++;
	}
	for(;i<=n;i++)
	{
		if(s[i]!='b') break;
		b++;
	}
	for(;i<=n;i++)
	{
		if(s[i]!='c') break;
		c++;
	}
	if(i<=n) printf("NO\n");
	else
	{
		if((a==c || b==c) && a && b && c) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}