#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	map<int, int> ans;
	queue<int> q;
	for(int i = 0; i <= 30; i++)
		if(n & (1 << i))
		{
			if(i > 0) q.push(1 << i);
			ans[1 << i]++;
		}
	if(int(ans.size()) > k)
	{
		puts("NO");
		return 0;
	}
	int cnt = ans.size();
	while(cnt < k && !q.empty())
	{
		int z = q.front();
		q.pop();
		ans[z]--;
		ans[z / 2] += 2;
		if(z / 2 > 1)
		{
			q.push(z / 2);
			q.push(z / 2);
		}
		cnt++;
	}
	if(cnt < k)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(auto x : ans)
		for(int i = 0; i < x.second; i++)
			printf("%d ", x.first);
	puts("");
	return 0;
}