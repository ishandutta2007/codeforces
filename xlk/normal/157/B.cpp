#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
#define scans(x) scanf("%s",&x);
#define scand(x) scanf("%lf",&x);
#define print(x) printf("%d ",&x);
const int inf=0x3fffffff;
using namespace std;
int n;
double a[1000];
double ans;
double pi=acos(-1);
int p=1;
int main()
{
	scan(n);
	fr(i,n)
		scand(a[i]);
	sort(a,a+n);
	rf(i,n)
	{
		ans+=p*a[i]*a[i]*pi;
		p=-p;
	}
	printf("%.10lf",ans);
	return 0;
}