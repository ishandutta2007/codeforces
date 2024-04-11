#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
bool ckmax(int &a, int b){ int c=a;a=max(a,b);return c!=a;}
bool ckmin(int &a, int b){ int c=a;a=min(a,b);return c!=a;}
bool ckmax(ll &a, ll b){ ll c=a;a=max(a,b);return c!=a;}
bool ckmin(ll &a, ll b){ ll c=a;a=min(a,b);return c!=a;}
int cnt0;char s[1000];
int main()
{
	int n,i;
	scanf("%i %s",&n,s+1);
	for(i=1;i<=n;i++) cnt0+=s[i]=='0';
	if(n==1 && s[1]=='0') return printf("0\n"),0;
	printf("1");
	for(i=0;i<cnt0;i++) printf("0");
	printf("\n");
	return 0;
}