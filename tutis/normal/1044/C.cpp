/*input
3
0 0
0 2
2 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	int x, y;
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	point a[n];
	for (point &i : a)
		cin >> i.x >> i.y;
	map<int, int>X;
	map<int, int>Y;
	for (int i = 0; i < n; i++)
	{
		X[a[i].x] = i;
		Y[a[i].y] = i;
	}
	vector<int>id;
	id.push_back((*(X.begin())).second);
	id.push_back((*(Y.begin())).second);
	id.push_back((*(--X.end())).second);
	id.push_back((*(--Y.end())).second);
	sort(id.begin(), id.end());
	int ANS4 = 0;
	for (int t = 0; t < 4; t++)
	{
		ANS4 += abs(a[id[t]].x - a[id[(t + 1) % 4]].x);
		ANS4 += abs(a[id[t]].y - a[id[(t + 1) % 4]].y);
	}
	int ANS3 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int id2 = 0; id2 < 4; id2++)
		{
			for (int id3 = 0; id3 < 4; id3++)
			{
				int GAL = 0;
				vector<int>ids = {i, id[id2], id[id3]};
				sort(ids.begin(), ids.end());
				for (int t = 0; t < 3; t++)
				{
					GAL += abs(a[ids[t]].x - a[ids[(t + 1) % 3]].x);
					GAL += abs(a[ids[t]].y - a[ids[(t + 1) % 3]].y);
				}
				ANS3 = max(ANS3, GAL);
			}
		}
	}
	cout << ANS3 << " ";
	for (int i = 4; i <= n; i++)
		cout << ANS4 << " ";

}