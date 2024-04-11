#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
int h[max_n],dp[max_n];
stack<int> s1,s2;
vector<int> jumps[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",h+i);
	s1.push(1);
	s2.push(1);
	for(int i=2;i<=n;++i)
	{
		while(s1.size()&&h[s1.top()]>h[i]) s1.pop();
		if(s1.size()) jumps[s1.top()].push_back(i);
		s1.push(i);
		while(s2.size()&&h[s2.top()]<h[i]) s2.pop();
		if(s2.size()) jumps[s2.top()].push_back(i);
		s2.push(i);
	}
	while(s1.size()) s1.pop();
	while(s2.size()) s2.pop();
	s1.push(n);
	s2.push(n);
	for(int i=n-1;i>=1;--i)
	{
		while(s1.size()&&h[s1.top()]>h[i]) s1.pop();
		if(s1.size()) jumps[i].push_back(s1.top());
		s1.push(i);
		while(s2.size()&&h[s2.top()]<h[i]) s2.pop();
		if(s2.size()) jumps[i].push_back(s2.top());
		s2.push(i);
	}
	for(int i=1;i<=n;++i) dp[i]=n;
	dp[1]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<jumps[i].size();++j)
			dp[jumps[i][j]]=min(dp[jumps[i][j]],dp[i]+1);
	printf("%d",dp[n]);
	return 0;
}