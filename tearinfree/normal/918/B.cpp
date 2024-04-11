#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

string na[1001],ia[1001];

int main() {
	int n,m;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> na[i] >> ia[i];
	string a,b;
	for(int i=0;i<m;i++) {
		cin >> a >> b;
		for(int i=0;i<n;i++) if(ia[i]+";"==b) {
			cout << a << ' ' << b << " #" << na[i] << endl;
			break;
		}
	}
	return 0;
}