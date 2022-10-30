#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1005;

int n, m, a[N][N];
vector<pair<int, int> > v;
bool g[N][N];

bool cmp(const pair<int, int> i, const pair<int, int > j) {
	return a[i.first][i.second] > a[j.first][j.second];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			v.push_back(make_pair(i, j));
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); ++i) {
		//cout << i <<  ' ' << a[v[i].first][v[i].second] << endl;
		g[v[i].first][v[i].second] = true;
		for (int j = 0; j < i; ++j) {
			if (v[i].first != v[j].first && v[i].second != v[j].second && g[v[i].first][v[j].second] && g[v[j].first][v[i].second]) {
				printf("%d\n", a[v[i].first][v[i].second]);
				return 0;
			}
		}
	}
	return 0;
}