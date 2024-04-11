#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],od[N],mx;
vector<int>t;
set<int>s;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		od[i]=i;
	}
	mx=0;
	s.clear();
	t.clear();
	sort(od+1,od+n+1,[&](int x,int y){return a[x]==a[y]?x>y:a[x]<a[y];});
	for(int i=1,j=1;i<=n;i++)
	{
		int p=od[i];
		if(a[p]!=a[od[i-1]])
		{
			for(auto i:t)
				s.insert(-i);
			t.clear();
		}
		while(s.size()&&-(*s.begin())>p)
		{
			s.erase(-od[j]);
			j++;
		}
		t.push_back(p);
		mx=max(mx,(int)s.size()+(int)t.size());
	}	
	printf("%d\n",n-mx);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}