#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=150;
char s[2][N];
int a[2][N];
int main()
{
	int n,i,j,sol=0;
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	n=strlen(s[0]+1);
	for(j=0;j<2;j++) for(i=1;i<=n;i++) a[j][i]=(s[j][i]=='0');
	/*for(i=1;i<n;i++)
	{
		int x=a[0][i]+a[1][i]+a[0][i+1]+a[1][i+1];
		if(x==3)
		{
			sol++;
			a[0][i]=a[1][i]=a[0][i+1]=a[1][i+1]=0;
		}
	}*/
	for(i=1;i<n;i++)
	{
		int x=a[0][i]+a[1][i]+a[0][i+1]+a[1][i+1];
		if(x==3)
		{
			sol++;
			a[0][i]=a[1][i]=a[0][i+1]=a[1][i+1]=0;
		}
		if(x==4)
		{
			sol++;
			a[0][i]=a[1][i]=a[0][i+1]=0;
		}
	}
	printf("%i\n",sol);
	return 0;
}