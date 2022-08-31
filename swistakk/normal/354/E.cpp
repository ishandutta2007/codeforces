#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define uint long long int
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

int dig[50][50];
vector<pair<int, int> > possib[10];


bool rec(ll n, int pos) {
	if (n < 0) {
		return false;
	}
	if (n == 0) {
		return true;
	}
	for (int i = 1; i <= 6; i++) {
		dig[i][pos] = 0;
	}
	if (n < 10) {
		if (n == 4) {
			dig[1][pos] = 4;
			return true;
		} if (n == 7) {
			dig[1][pos] = 7;
			return true;
		} else if (n == 8) {
			dig[1][pos] = 4;
			dig[2][pos] = 4;
		} else {
			return false;
		}
	}
	for (int i = 0; i < possib[n % 10].size(); i++) {
		int fours = possib[n % 10][i].first, sevens = possib[n % 10][i].second;
		for (int j = 1; j <= fours; j++) {
			dig[j][pos] = 4;
		}
		for (int j = fours + 1; j <= fours + sevens; j++) {
			dig[j][pos] = 7;
		}
		for (int j = fours + sevens + 1; j <= 6; j++) {
			dig[j][pos] = 0;
		}
		if (rec((n - 4 * fours - 7 * sevens) / 10, pos + 1)) {
			return true;
		}
	}
	return false;
}

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; i + j <= 6; j++) {
			possib[(4 * i + 7 * j) % 10].PB(MP(i, j));
		}
	}
	
	ll t;
	cin>>t;
	for (int z = 1; z <= t; z++) {
		ll n;
		cin>>n;
		for (int i = 1; i <= 6; i++) {
			for (int j = 0; j <= 20; j++) {
				dig[i][j] = 0;
			}
		}
		if (rec(n, 0)) {
			for (int i = 1; i <= 6; i++) {
				bool print = false;
				for (int j = 20; j >= 0; j--) {
					if (dig[i][j] || j == 0) {
						print = true;
					}
					if (print) {
						cout<<dig[i][j];
					}
				}
				cout<<" ";
			}
			cout << "\n";
		} else {
			cout<<"-1\n";
		}
	}
	
	// nie zapomnij o ll
	return 0;
}