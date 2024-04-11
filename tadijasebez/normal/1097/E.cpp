#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
void Solve()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n),p(n+1);
	vector<vector<int> > dec(n);
	vector<bool> was(n,0);
	for(int &i:a) scanf("%i",&i);
	for(int i=0;i<n;i++) p[a[i]]=i;
	int cnt=n;
	int lsz=0;
	vector<vector<int> > ans;
	vector<int> lvl(n);
	while(cnt>0)
	{
		int need=0;
		while((need+1)*(need+2)/2<=cnt) need++;
		for(int i=0;i<lsz;i++) dec[i].clear();
		vector<int> lis;
		lsz=0;
		for(int i=0;i<n;i++) if(!was[i])
		{
			int id=lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
			if(id==lis.size()) lis.pb(0);
			dec[id].pb(a[i]);
			lis[id]=a[i];
			lvl[i]=id;
		}
		lsz=lis.size();
		int cool=lsz-1;
		lis.clear();
		for(int i=n-1;~i;i--) if(!was[i])
		{
			if(lvl[i]==cool)
			{
				cool--;
				lis.pb(a[i]);
			}
		}
		reverse(lis.begin(),lis.end());
        if(lsz>need)
		{
			cnt-=lsz;
			ans.pb(lis);
			for(int i:lis) was[p[i]]=1;
		}
		else
		{
			for(int i=0;i<lsz;i++) ans.pb(dec[i]);
			break;
		}
	}
	printf("%i\n",ans.size());
	for(vector<int> v:ans)
	{
		printf("%i ",v.size());
		for(int i:v) printf("%i ",i);
		printf("\n");
	}
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--) Solve();
}