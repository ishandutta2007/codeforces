#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int a[100005];
priority_queue <pair<int,int> > q;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,x;
		cin >> n >> m >> x;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		while(!q.empty()) q.pop();
		for(int i=1;i<=m;i++)
			q.push({0,i});
		cout << "YES\n";
		for(int i=1;i<=n;i++)
		{
			int x=q.top().first,y=q.top().second;
			q.pop();
			q.push({x-a[i],y});
			cout << y << " "; 
		}
		cout << "\n";
	}
	return 0;
}