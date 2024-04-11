#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=1050;
int cnt[N];
vector<pair<int,int> > edges;
int main()
{
	int n,i,u,v;bool ok=1;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		if(u==n) cnt[v]++;
		else if(v==n) cnt[u]++;
		else ok=0;
	}
	if(cnt[n]>0 || ok==0) return 0*printf("NO\n");
    vector<int> zero;
    for(i=1;i<n;i++) if(cnt[i]==0) zero.pb(i);
    vector<pair<int,int> > work;
    for(i=n-1;i>=1;i--) if(cnt[i]>0) work.pb(mp(i,cnt[i]));
    int last=n;
    for(auto p:work)
	{
		int i=p.first,c=p.second-1;
		while(c--)
		{
			if(zero.empty() || zero.back()>i) return 0*printf("NO\n");
			edges.pb(mp(zero.back(),last));
			last=zero.back();
			zero.pop_back();
		}
		edges.pb(mp(i,last));
		last=i;
	}
	if(zero.size()) return 0*printf("NO\n");
	printf("YES\n");
	for(i=0;i<edges.size();i++) printf("%i %i\n",edges[i].first,edges[i].second);
	return 0;
}