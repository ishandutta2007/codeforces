#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],id[max_n],Next[max_n];
typedef pair<int,int> P;
vector<P> w,b;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		id[i]=n+1;
	}
	for(int i=n;i>=1;--i)
	{
		Next[i]=id[a[i]];
		id[a[i]]=i;
	}
	w.push_back(P(0,n+1));
	b.push_back(P(0,n+1));
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==w.back().first)
		{
			if(a[i]!=b.back().first)
				++ans;
			b.push_back(P(a[i],Next[i]));
		}
		else if(a[i]==b.back().first)
		{
			++ans;
			w.push_back(P(a[i],Next[i]));
		}
		else
		{
			++ans;
			if(w.back().second<b.back().second)
				w.push_back(P(a[i],Next[i]));
			else
				b.push_back(P(a[i],Next[i]));
		}
	}
	printf("%d\n",ans);
	return 0;
}