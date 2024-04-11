#include <bits/stdc++.h>
using namespace std;

const int N = 11111;

int n, k, a, b, c, d;
bool vis[N];

vector <int> All;

main(void) {
	cin >> n >> k >> a >> b >> c >> d;
	if(k < n + 1 || n <= 4) {
		puts("-1");
		return 0;
	}
	vis[a] = vis[b] = vis[c] = vis[d] = 1;
	All.clear();
	cout << a <<" " << c << " ";
	for(int i = 1; i <= n; ++ i) if(!vis[i]) All.push_back(i), cout << i << " ";
	cout << d <<" "<< b << endl;
	cout << c <<" "<< a <<" ";
	for(int i = 0; i < (int) All.size(); ++ i) cout << All[i] <<" ";
	cout << b << " " << d << endl;
}