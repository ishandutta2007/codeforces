#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

struct Po {
	int x, y;
	friend Po operator - (Po a, Po b) {
		return (Po){a.x - b.x, a.y - b.y};
	}
	void input() {
		scanf("%d%d", &x, &y);
	}
	long long norm() {
		return 1LL * x * x + 1LL * y * y;
	}
}P[N];

int n;
bool vis[N];
long long mx;
int who;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) P[i].input();
	cout << 1 <<  ' ';
	vis[1] = 1; int lst = 1;
	for(int i = 1; i < n; ++ i) {
		mx = who = 0;
		for(int j = 1; j <= n; ++ j) if(!vis[j]) {
			if((P[j] - P[lst]).norm() > mx) {
				who = j;
				mx = ((P[j] - P[lst]).norm());
			}
		}
		vis[who] = 1; lst = who;
		cout <<who <<' ';
	}
	cout << endl;
}