#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int ans,n,a[Maxn],cnt[Maxn],have;
set <int> Se[Maxn];
map <int,int> Ma;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=100000;i++)
		Se[0].insert(i);
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i]]) 
			Ma[cnt[a[i]]]--;
		if(Ma[cnt[a[i]]]==0) 
			Ma.erase(Ma.find(cnt[a[i]]));
		Se[cnt[a[i]]].erase(Se[cnt[a[i]]].find(a[i]));
		cnt[a[i]]++;
		Se[cnt[a[i]]].insert(a[i]);
		Ma[cnt[a[i]]]++;
		if(Ma.size()==2)
		{
			map <int,int>::iterator it=Ma.begin(),it2=Ma.begin();
			it2++;
			if((it2->first-it->first==1&&it2->second==1)||(it->first==1&&it->second==1)||(it2->first==1&&it2->second==1)) ans=i;
		}
		if(Ma.size()==1)
			if(Ma.begin()->second==1||Ma.begin()->first==1) ans=i;
	}
	printf("%d",ans);
	return 0;
}