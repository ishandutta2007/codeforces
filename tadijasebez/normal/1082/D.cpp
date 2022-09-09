#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
int a[N],diam;
vector<pair<int,int> > edges;
void Output()
{
	printf("YES %i\n",diam-1);
	printf("%i\n",edges.size());
	for(auto p:edges) printf("%i %i\n",p.first,p.second);
}
void Nope()
{
	printf("NO\n");
	exit(0);
}
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<int> lef,nod;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]==1) lef.pb(i);
		else nod.pb(i);
	}
	if(nod.size()==0) Nope();
	diam=nod.size();
	for(i=1;i<nod.size();i++) edges.pb(mp(nod[i-1],nod[i])),a[nod[i-1]]--,a[nod[i]]--;
	if(lef.size()==0) Output();
	else if(lef.size()==1) diam++,edges.pb(mp(lef[0],nod[0])),Output();
	else
	{
		a[nod[0]]--;
		diam++;
		edges.pb(mp(lef[0],nod[0]));
		if(a[nod.back()]<=0) Nope();
		a[nod.back()]--;
		diam++;
		edges.pb(mp(lef[1],nod.back()));
		int j=2;
		for(i=0;i<nod.size();i++)
		{
			while(a[nod[i]]>0 && j<lef.size())
			{
				a[nod[i]]--;
				edges.pb(mp(lef[j],nod[i]));
				j++;
			}
		}
		if(j!=lef.size()) Nope();
		Output();
	}
	return 0;
}