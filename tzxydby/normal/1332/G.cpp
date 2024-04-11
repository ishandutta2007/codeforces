#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,a[N],c[N],l[N],r[N];
vector<int>s[N],p[N],b;
set<int>s1,s2,s3,s4,s5,s6,s7;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		p[l[i]].push_back(i);
	}
	for(int i=n;i;i--)
	{
		int x;
		while(s1.size()&&a[x=*s1.begin()]<a[i])
		{
			s6.insert(x);
			c[x]--;
			if(!c[x])
				s5.insert(x);
			s1.erase(x);
		}
		while(s2.size()&&a[x=*s2.begin()]>a[i])
		{
			s7.insert(x);
			c[x]--;
			if(!c[x])
				s5.insert(x);
			s2.erase(x);
		}
		while(s3.size()&&a[x=*s3.begin()]<=a[i])
			s3.erase(x);
		while(s4.size()&&a[x=*s4.begin()]>=a[i])
			s4.erase(x);
		if(s3.size()&&s4.size())
		{
			auto it=s5.lower_bound(max(*s3.begin(),*s4.begin()));
			if(it!=s5.end()&&(!b.size()||*it<b.back()))
			{
				b={i,*it};
				auto it2=s1.lower_bound(*it);
				it2--;
				b.push_back(*it2);
				it2=s2.lower_bound(*it);
				it2--;
				b.push_back(*it2);
				sort(b.begin(),b.end());
			}
		}
		for(int j:p[i])
		{
			if(b.size()&&b.back()<=r[j])
				s[j]=b;
			else
			{
				if(s3.size())
				{
					auto it=s6.lower_bound(*s3.begin());
					if(it!=s6.end()&&*it<=r[j])
						s[j]={i,*it-1,*it};
				}
				if(s4.size())
				{
					auto it=s7.lower_bound(*s4.begin());
					if(it!=s7.end()&&*it<=r[j])
						s[j]={i,*it-1,*it};
				}
			}
		}
		c[i]=2;
		s1.insert(i),s2.insert(i),s3.insert(i),s4.insert(i);
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",s[i].size());
		for(auto j:s[i])
			printf("%d ",j);
		puts("");
	}
	return 0;
}