#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
inline void solve(int a,int b)
{
	int x=(a+b)>>1,y=a+b-x;
	for(int i=max(a-y,0);i<=min(a,x);++i)
		ans.push_back((a-i)+(x-i));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ans.clear();
		solve(a,b);
		solve(b,a);
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end())-ans.begin());
		printf("%d\n",(int)ans.size());
		for(int i=0;i<int(ans.size());++i)
			printf("%d%c",ans[i],i+1<(int)ans.size()?' ':'\n');
	}
	return 0;
}