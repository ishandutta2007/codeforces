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
#define scand(x) scanf("%lf",x);
#define print(x) printf("%d ",x);
const int inf=0x3fffffff;
const double pi=acos(-1.);
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<int> vi;
int n;
int a[1020];
char s[10020];
char c[10020];
int ans;
int main()
{
	scan(n);
	scanf("%s",s);
	int i;
	for(i=0;i<n;i++)
		c[i]=s[i+n];
	sort(s,s+n);
	sort(c,c+n);
	for(i=0;i<n;i++)
		if(s[i]>=c[i])
			break;
	if(i==n)
		ans=1;
	for(i=0;i<n;i++)
		if(s[i]<=c[i])
			break;
	if(i==n)
		ans=1;
	puts(ans?"YES":"NO");
	return 0;
}