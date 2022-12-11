#include<bits/stdc++.h>
#define maxn 600005
using namespace std;
const int bas = 27;
int n,q;
char s[maxn],a[8],b[8];
vector<int> pos[maxn];
map<pair<int,int>,int> Ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		int x=0;
		for(int j=i;j<=min(n,i+3);++j)
		{
			x=x*bas+s[j]-'a'+1;
			pos[x].push_back(i);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s%s",a+1,b+1);
		int lena=strlen(a+1),lenb=strlen(b+1);
		int x=0,y=0;
		for(int i=1;i<=lena;++i)x=x*bas+a[i]-'a'+1;
		for(int i=1;i<=lenb;++i)y=y*bas+b[i]-'a'+1;
		if(pos[x].size()>pos[y].size())swap(x,y),swap(lena,lenb);
		if(Ans.count(make_pair(x,y)))
		{
			printf("%d\n",Ans[make_pair(x,y)]);
			continue;
		}
		int ans=10000000;
		for(int u:pos[x])
		{
			auto p1=lower_bound(pos[y].begin(),pos[y].end(),u);
			if(p1!=pos[y].end())
			{
				ans=min(ans,max(u+lena,(*p1)+lenb)-u);
			}
			if(p1!=pos[y].begin())
			{
				--p1;
				ans=min(ans,max(u+lena,(*p1+lenb))-(*p1));
			}
		}
		if(ans==10000000)ans=-1;
		printf("%d\n",ans);
		Ans[make_pair(x,y)]=ans;
	}
}