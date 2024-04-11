#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int mp[4001][4001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	//map<ar<int, 2>, int> mp;
	//mp[{}]=n;
	mp[2000][2000]=n;
	queue<ar<int, 2>> qu;
	qu.push({});
	while(qu.size()) {
		ar<int, 2> u=qu.front();
		qu.pop();
		int a=mp[u[0]+2000][u[1]+2000]/4;
		if(!a)
			continue;
		//mp[u]-=4*a;
		mp[u[0]+2000][u[1]+2000]-=4*a;
		//mp[{u[0]-1, u[1]}]+=a;
		//mp[{u[0]+1, u[1]}]+=a;
		//mp[{u[0], u[1]-1}]+=a;
		//mp[{u[0], u[1]+1}]+=a;
		mp[u[0]-1+2000][u[1]+2000]+=a;
		mp[u[0]+1+2000][u[1]+2000]+=a;
		mp[u[0]+2000][u[1]-1+2000]+=a;
		mp[u[0]+2000][u[1]+1+2000]+=a;
		qu.push({u[0]-1, u[1]});
		qu.push({u[0]+1, u[1]});
		qu.push({u[0], u[1]-1});
		qu.push({u[0], u[1]+1});
	}
	while(t--) {
		int x, y;
		cin >> x >> y;
		//cout << mp[{x, y}] << "\n";
		cout << (x>=-2000&&x<=2000&&y>=-2000&&y<=2000?mp[x+2000][y+2000]:0) << "\n";
	}
	//for(int i=-40; i<=40; ++i) {
		//for(int j=-40; j<=40; ++j) {
			//cout << mp[{i, j}] << " ";
		//}
		//cout << endl;
	//}
}