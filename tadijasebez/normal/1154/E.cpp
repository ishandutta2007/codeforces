#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int a[N],p[N],ans[N];
bool was[N];
int main()
{
	int n,i,k;
	scanf("%i %i",&n,&k);
	set<int> pos;
	for(i=1;i<=n;i++) scanf("%i",&a[i]),p[a[i]]=i,pos.insert(i);
	int ptr=n,pl=1;
	for(;;pl=3-pl)
	{
		for(;was[ptr];ptr--);
		if(ptr==0) break;
		auto it=pos.find(p[ptr]);
		for(i=1;i<=k;i++)
		{
			auto it2=it;
			it2++;
			if(it2!=pos.end()) was[a[*it2]]=1,ans[*it2]=pl,pos.erase(it2);
			it2=it;
			if(it2!=pos.begin()) it2--,was[a[*it2]]=1,ans[*it2]=pl,pos.erase(it2);
		}
		was[ptr]=1;ans[p[ptr]]=pl;pos.erase(it);
	}
	for(i=1;i<=n;i++) printf("%i",ans[i]);
	return 0;
}