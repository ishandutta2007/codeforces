#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=400050;
int B[N],C[N],a[N],b[N],num,cnt;
bool ok[N];
vector<int> id,sol;
vector< pair<int,int> > X[N];
int main()
{
	int n,m,p,i,j;
	scanf("%i %i %i",&n,&m,&p);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id.push_back(a[i]);
	for(i=1;i<=m;i++) scanf("%i",&b[i]),id.push_back(b[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) a[i]=lower_bound(id.begin(),id.end(),a[i])-id.begin()+1;
	for(i=1;i<=m;i++) b[i]=lower_bound(id.begin(),id.end(),b[i])-id.begin()+1;
	for(i=1;i<=n;i++) X[i%p].push_back(make_pair(a[i],i));
	for(i=1;i<=m;i++)
	{
		if(!B[b[i]]) num++;
		B[b[i]]++;
	}
	for(j=0;j<p;j++)
	{
		cnt=0;
		for(i=0;i<X[j].size();i++)
		{
			int v=X[j][i].first;
			if(C[v]==B[v]) cnt--;
			C[v]++;
			if(C[v]==B[v]) cnt++;
			if(i>=m)
			{
				int u=X[j][i-m].first;
				int w=X[j][i-m+1].second;
				if(C[u]==B[u]) cnt--;
				C[u]--;
				if(C[u]==B[u]) cnt++;
				if(cnt==num) sol.push_back(w);
			}
			if(i==m-1 && cnt==num) sol.push_back(X[j][0].second);
		}
		for(i=0;i<X[j].size();i++) C[X[j][i].first]=0;
	}
	sort(sol.begin(),sol.end());
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	return 0;
}