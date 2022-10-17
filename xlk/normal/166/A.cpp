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
int n,k;
ii a[1020];
int main()
{
	scan(n);
	scan(k);
	k--;
	fr(i,n)
	{
		scan(a[i].first);
		a[i].first=-a[i].first;
		scan(a[i].second);
	}
	sort(a,a+n);
	printf("%d",upper_bound(a,a+n,a[k])-lower_bound(a,a+n,a[k]));
	return 0;
}