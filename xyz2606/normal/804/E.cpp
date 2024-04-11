#include<bits/stdc++.h>
using namespace std;
int t45[20][2] = {
	{3, 7},
	{1, 6},
	{2, 9},
	{1, 7},
	{1, 5},
	{3, 6},
	{2, 7},
	{4, 9},
	{3, 9},
	{3, 8},
	{3, 5},
	{4, 5},
	{4, 6},
	{2, 6},
	{4, 7},
	{4, 8},
	{1, 8},
	{1, 9},
	{2, 8},
	{2, 5}};
int t44[16][2] = {
	{4, 5},
	{1, 6},
	{3, 6},
	{1, 7},
	{1, 5},
	{3, 8},
	{3, 5},
	{1, 8},
	{2, 6},
	{4, 7},
	{2, 7},
	{2, 5},
	{3, 7},
	{4, 6},
	{4, 8},
	{2, 8}
};
int ans4[6][2] = {
	{2, 4},
{1, 3},
{2, 3},
{1, 4},
{1, 2},
{3, 4}
};
int ans5[10][2] = {
	{3, 5},
{1, 3},
{4, 5},
{2, 3},
{1, 2},
{1, 5},
{2, 5},
{3, 4},
{2, 4},
{1, 4}
};
int main() {
	int n;
	scanf("%d", &n);
	if(n % 4 == 2 || n % 4 == 3) {
		printf("NO\n");
	}else {
		printf("YES\n");
		if(n == 1) {
			return 0;
		}
		vector<pair<int, int> > v;
		for(int i(1); i <= n; i += 4) {
			if(i + 3 == n - 1) {
				v.push_back({i, i + 4});
				break;
			} else v.push_back({i, i + 3});
		}
		for(int i(0); i < (int)v.size(); i++) {
			int delta(v[i].first - 1);
			if(v[i].second - v[i].first + 1 == 4) {
				for(int i(0); i < 6; i++)
					printf("%d %d\n", ans4[i][0] + delta, ans4[i][1] + delta);
			}else {
				for(int i(0); i < 10; i++)
					printf("%d %d\n", ans5[i][0] + delta, ans5[i][1] + delta);
			}
			for(int j(i + 1); j < (int)v.size(); j++) {
				int dj(v[j].first - 5);
				if(v[j].second - v[j].first + 1 == 4) {
					for(int i(0); i < 16; i++)
						printf("%d %d\n", t44[i][0] + delta, t44[i][1] + dj);
				}else {
					for(int i(0); i < 20; i++)
						printf("%d %d\n", t45[i][0] + delta, t45[i][1] + dj);
				}
			}
		}
	}
}