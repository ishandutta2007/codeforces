#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=5050;
int a[N],sol[N];
int pos(int x){ return x>0?x:-x;}
map<int,int> id;
bool was[N];
int cnt;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		for(j=2;j*j<=pos(a[i]);j++)
		{
			while(a[i]%(j*j)==0) a[i]/=j*j;
		}
            if(!a[i]) continue;
		if(!id[a[i]]) id[a[i]]=++cnt;
		a[i]=id[a[i]];
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++) was[j]=0;
		int ans=0,zero=0;
		for(j=i;j<=n;j++)
		{
			if(!was[a[j]]) ans++;
			if(!a[j]) zero=1;
			was[a[j]]=1;
			sol[max(ans-zero,1)]++;
		}
	}
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}