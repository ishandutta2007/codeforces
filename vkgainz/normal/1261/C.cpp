#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second
 
int n, m;
vector<vector<int>> a, b;
 
void sz(vector<vector<int>> &v){
	v.assign(n + 2, vector<int>(m + 2));
}
 
bool f(int x){
	x = 2 * x + 1;
	for(int i = n; i; i--)
	for(int j = m; j; j--){
		if(a[i][j] >= x) b[i][j] = a[i][j];
		else b[i][j] = max({1, b[i + 1][j], b[i][j + 1], b[i + 1][j + 1]}) - 1;
		if(a[i][j] && !b[i][j]) return 0;
	}
	return 1;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	sz(a), sz(b);
	
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++){
		char c;
		cin >> c;
		if(c == 'X') a[i][j] = min({a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]}) + 1;
	}
	
	int l = 0, r = min(n, m);
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(f(mid)) l = mid;
		else r = mid;
	}
	
	cout << l << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << (i + l <= n && j + l <= m && 
				a[i + l][j + l] >= 2 * l + 1 ? 'X' : '.');
		}
		cout << endl;
	}
	
	return 0;
}