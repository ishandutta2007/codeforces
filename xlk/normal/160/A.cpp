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
int a[120];
int f[10020];
int sum;
int main()
{
	scan(n);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	fr(i,n)
	{
		scan(a[i]);
		sum+=a[i];
		for(int j=10000;j>=a[i];j--)
			f[j]=min(f[j],f[j-a[i]]+1);
	}
	int i;
	int ans=inf;
	for(i=(sum+2)/2;i<=sum;i++)
		ans=min(ans,f[i]);
	printf("%d",ans);
	return 0;
}