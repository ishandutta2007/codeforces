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
int f[1000020];
int g[1000020];
char a[1020];
char b[1020];
int la,lb,m,p;
int main()
{
	scan(n);
	scanf("%s",a);
	scanf("%s",b);
	la=strlen(a);
	lb=strlen(b);
	m=la*lb;
	fr(i,m)
	{
		if(i)
			f[i]=f[i-1];
		if(i)
			g[i]=g[i-1];
		if(a[i%la]=='R'&&b[i%lb]=='S')
			f[i]++;
		else if(a[i%la]=='S'&&b[i%lb]=='P')
			f[i]++;
		else if(a[i%la]=='P'&&b[i%lb]=='R')
			f[i]++;

		if(a[i%la]=='S'&&b[i%lb]=='R')
			g[i]++;
		else if(a[i%la]=='P'&&b[i%lb]=='S')
			g[i]++;
		else if(a[i%la]=='R'&&b[i%lb]=='P')
			g[i]++;
	}
	printf("%d %d",(n-1)/m*g[m-1]+g[(n-1)%m],(n-1)/m*f[m-1]+f[(n-1)%m]);
	return 0;
}