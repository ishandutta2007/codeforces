#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
int a[N],b[N];
vector<int> v[N];
int main()
{
	int n,i,c=0,j,k;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),v[n-a[i]].pb(i);
	for(i=1;i<=n;i++)
	{
		if(v[i].size()%i) return 0*printf("Impossible\n");
		for(j=0;j<v[i].size();j+=i)
		{
			c++;
			for(k=0;k<i;k++) b[v[i][j+k]]=c;
		}
	}
	printf("Possible\n");
	for(i=1;i<=n;i++) printf("%i ",b[i]);
	return 0;
}