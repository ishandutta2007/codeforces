#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;
 


#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define pii pair<int, int>
#define vi vector<int>
const double Pi = acos(-1);
const int MOD = 1000000007;
const int inf = 1000000000;
const long long INF = 10000000000000000000LL;


struct point
{
	int x, y;
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};


point operator +(point a, point b) {
	return point(a.x + b.x, a.y + b.y);
}


point operator -(point a, point b) {
	return point(a.x - b.x, a.y - b.y);
}



const int MAXN = 200001;
int n, x;
double p[101];


void get(int m, vector<double> &dp) {
	if (m == 1) {
		for (int i = 0; i <= x; i++) {
			dp[i] = p[i];
		}  
	} else {
		if (m % 2 == 1) {
			vector<double> dp1;
			dp1.resize(129);
			get(m - 1, dp1);
			for (int i = 0; i < (int)dp1.size(); i++) {
				for (int j = 0; j <= x; j++) {
					dp[(i ^ j)]+= dp1[i] * p[j];
				}
			}
		} else {
			vector<double> dp1;
			dp1.resize(129);
			get(m / 2, dp1);
			for (int i = 0; i < (int)dp1.size(); i++) {
				for (int j = 0; j < (int)dp1.size(); j++) {
					dp[(i ^ j)] += dp1[i] * dp1[j];
				}
			}
		}
	}
}


int main() {
	cin >> n >> x;
	for (int i = 0; i <= x; i++) {
		cin >> p[i];
	}
	vector<double> dp;
	dp.resize(129);
	get(n, dp);
	cout << fixed << 1.0 - dp[0] << endl;
	return 0;
}