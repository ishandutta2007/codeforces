#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
const int N=200050;
char s[N],t[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int a=0,b=0,c=0,d=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='0') a++;
		else b++;
		if(t[i]=='0')
		{
			if(s[i]=='0') c++;
			else d++;
		}
	}
	ll sol=(ll)c*b+(ll)d*a-(ll)c*d;
	printf("%lld\n",sol);
	//printf("%i %i %i %i\n",a,b,c,d);
	return 0;
}