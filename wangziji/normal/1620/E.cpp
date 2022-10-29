#include <bits/stdc++.h>
using namespace std;
vector <int> v[500005];
int ans[500005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	int cnt=0;
	while(q--)
	{
		int op,x,y;
		cin >> op >> x;
		if(op==1)
			v[x].push_back(++cnt);
		else
		{
			cin >> y;
			if(x==y) continue;
			if(v[x].size()>v[y].size()) swap(v[x],v[y]);
			for(auto t:v[x]) v[y].push_back(t);
			v[x].clear();
		}
	}
	for(int i=1;i<=500000;i++)
		for(auto t:v[i]) ans[t]=i;
	for(int i=1;i<=cnt;i++)
		cout << ans[i] << " ";
	return 0;
}