/*input
5
3 -3 0
2 -1 1
4 2 4
2 3 7
3 6 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin >> n;
	set<int>idomu;
	map<int, vector<int>>plius;
	map<int, vector<int>>minus;
	while (n--)
	{
		int l, r, h;
		cin >> h >> l >> r;
		idomu.insert(l);
		idomu.insert(r);
		plius[l].push_back(h);
		minus[r].push_back(h);
	}
	multiset<int>H;
	map<int, int>Hei;
	map<int, int>HeiPo;
	map<int, int>HeiPries;
	H.insert(0);
	vector<pair<int, int>>ans;
	for (int x : idomu)
	{
		vector<int>y;
		y.push_back(*(--H.end()));
		for (int h : plius[x])
		{
			H.insert(h);
		}
		y.push_back(*(--H.end()));
		for (int h : minus[x])
		{
			H.erase(H.find(h));
		}
		y.push_back(*(--H.end()));
		for (int h : y)
		{
			while (ans.size() >= 2 && ans[ans.size() - 1].second == h && ans[ans.size() - 2].second == h)
				ans.pop_back();
			while (!ans.empty() && ans.back() == make_pair(x, h))
				ans.pop_back();
			ans.push_back({x, h});
		}
	}
	cout << ans.size() << "\n";
	for (pair<int, int>a : ans)
	{
		cout << a.first << " " << a.second << "\n";
	}


}