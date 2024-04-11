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

int main()
{
	int a,b,c,n;
	scanf("%i %i %i %i",&a,&b,&c,&n);
	if(n<=a+b-c || c>a || c>b) printf("-1\n");
	else printf("%i\n",n-a-b+c);
	return 0;
}