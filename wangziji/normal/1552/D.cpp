#include <bits/stdc++.h>
using namespace std;
int a[12],n;
inline bool dfs(int now,int sum,int cnt)
{
	if(now==n+1)
		return sum==0&&cnt;
	return dfs(now+1,sum,cnt)|dfs(now+1,sum+a[now],1)|dfs(now+1,sum-a[now],1);
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		if(dfs(1,0,0))
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}