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
#include <cstring>
#define uint long long int
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

ll nwd(ll a, ll b) {
	if (b > a) {
		swap(a, b);
	}
	if (b == 0) {
		return a;
	}
	return nwd(b, a % b);
}

const int N = 1001 * 1001;

char buffs[2][N];
int chars[26][N];
int len[2];

int main()
{
	// nie zapomnij o ll
	ll n, m;
	cin>>n>>m;
	for (int i = 0; i < 2; i++) {
		scanf("%s", buffs[i]);
		len[i] = strlen(buffs[i]);
	}
	
	ll gcd = nwd(len[0], len[1]);
	ll length = len[0] * n;
	ll res = length;
	ll nww = (len[0] / gcd) * len[1];
	ll reps = len[0] * n / nww;
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < len[i]; j++) {
			chars[int(buffs[i][j]) - int('a')][j % gcd]++;
		}
	}
	for (int i = 0; i < len[1]; i++) {
		res -= reps * chars[int(buffs[1][i]) - int('a')][i % gcd];
	}
// 	for (int i = 0; i < gcd; i++) {
// 		for (int j = 0; j < 30; j++) {
// 			// res -= reps * chars[j][i][0] * chars[j][i][1];
// 		}
// 	}
	cout<<res<<endl;
	
	
	
	
	
	// nie zapomnij o ll
	return 0;
}