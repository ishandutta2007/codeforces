#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5+5;
int a[mxN];
#define FOR(x) for(int i=0;i<x;++i)
void solve()
{
	int n;
	cin >> n;
 
	vector<array<int, 2>> V;
	FOR(n){
		int a, b;
		cin >> a >> b;
		V.push_back({a, 1});
		V.push_back({b,-1});
	}
	// Sort the info - make sure to make 1 and -1, because you dont want to count people alive before people who die.
	
	sort(V.begin(), V.end());
	
	pair<int, int> mx(0, 0);
	// max stores the maxmimum
	// pos stores the current amount of people alive
	int pos=0;
	
	for(int i =0; i < 2*n; i++){
		pos+=V[i][1];
		if(mx.first < pos) {
			mx.first=pos;
			mx.second=V[i][0];
		}
	}
	cout << mx.second << " " << mx.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
}