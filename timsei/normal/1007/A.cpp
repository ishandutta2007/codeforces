#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

int  n, A[N];
map <int, int> Map;

vector <pair <int, int> > C;

int num[N], ans;

int main(void) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), ++ Map[A[i]];
	for(map <int, int> ::iterator it = Map.begin(); it != Map.end(); ++ it) ++ num[it -> second];
	for(int i = n; i >= 1; -- i) num[i] += num[i + 1], ans += max(0, num[i] - 1);
	cout << ans << endl;
}