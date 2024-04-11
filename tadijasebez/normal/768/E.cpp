#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
map<pair<ll,int> ,int> dp;
map<pair<ll,int> ,bool> was;
int Grundy(ll mask, int n, int prv=60)
{
	if(!n) return 0;
	int i;
	for(i=n;i<=prv;i++) if(mask&((ll)1<<i)) mask^=(ll)1<<i;
	if(was[mp(mask,n)]) return dp[mp(mask,n)];
	bool vis[62];for(i=0;i<62;i++) vis[i]=0;
	for(i=0;i<n;i++)
	{
		if(!(mask&((ll)1<<i)))
		{
			int add=Grundy(mask^((ll)1<<i),n-i-1,n);
			vis[add]=1;
		}
	}
	int ret=0;
	for(i=0;i<62;i++) if(!vis[i]){ ret=i;break;}
	dp[mp(mask,n)]=ret;
	was[mp(mask,n)]=1;
	return ret;
}
int grundy[62],x;
int main()
{
	int n,p,i;
	for(i=1;i<=60;i++) grundy[i]=Grundy(0,i);
	scanf("%i",&n);
	while(n--) scanf("%i",&p),x^=grundy[p];
	if(!x) printf("YES\n");
	else printf("NO\n");
	return 0;
}