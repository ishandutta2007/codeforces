#include <bits/stdc++.h>
using namespace std;
set<int> fr,lo;
const int N=200050;
int l[N],r[N],sz[N],a[N];
vector<int> my[N];
int main()
{
	int n,q,i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(!a[i]) fr.insert(i);
		else
		{
			sz[a[i]]++;
			r[a[i]]=i;
			if(!l[a[i]]) l[a[i]]=i;
			lo.insert(i);
			my[a[i]].push_back(i);
		}
	}
	for(i=q;i>=1;i--)
	{
		//printf("%i\n",i);
		for(int j:my[i]) lo.erase(j);
        if(!sz[i] && i==q)
		{
			if(fr.empty()) return 0*printf("NO\n");
			a[*fr.begin()]=i;
			fr.erase(*fr.begin());
		}
		else
		{
			if(lo.lower_bound(l[i])!=lo.upper_bound(r[i])) return 0*printf("NO\n");
			for(auto it=fr.lower_bound(l[i]);it!=fr.upper_bound(r[i]);it++) a[*it]=i;//,printf("%i ",*it);
			fr.erase(fr.lower_bound(l[i]),fr.upper_bound(r[i]));
		}
	}
	for(auto it=fr.begin();it!=fr.end();it++) a[*it]=1;
	printf("YES\n");
	for(i=1;i<=n;i++) printf("%i%c",a[i],i==n?'\n':' ');
	return 0;
}