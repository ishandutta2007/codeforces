#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
const int inf=1e9+7;
const ll oo=9e18;
bool was[N];
int u[N],v[N];
void Run()
{
	vector<int> mtc;
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n*3;i++) was[i]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%i %i",&u[i],&v[i]);
		if(!was[u[i]] && !was[v[i]])
		{
			mtc.pb(i);
			was[u[i]]=1;
			was[v[i]]=1;
		}
	}
	if(mtc.size()>=n)
	{
		printf("Matching\n");
		for(int i=0;i<n;i++) printf("%i ",mtc[i]);
		printf("\n");
	}
	else
	{
		printf("IndSet\n");
		int cnt=0;
		for(int i=1;i<=3*n;i++) if(!was[i])
		{
			printf("%i ",i);
			cnt++;
			if(cnt==n) break;
		}
		printf("\n");
	}
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--) Run();
	return 0;
}