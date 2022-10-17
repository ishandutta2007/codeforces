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
int n,m,x,z;
vector<int>a;
int main()
{
	scan(n);
	scan(m);
	fr(i,n)
	{
		scan(x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	if(*lower_bound(a.begin(),a.end(),m)!=m)
	{
		a.push_back(m);
		sort(a.begin(),a.end());
		z++;
	}
	while(a[(a.size()+1)/2-1]!=m)
	{
		if(a[(a.size()+1)/2-1]>m)
		{
			a.push_back(0);
			sort(a.begin(),a.end());
		}
		else
			a.push_back(100020);
		z++;
	}
	printf("%d",z);
	return 0;
}