#include<vector>
#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int G = 1000001;
int mem[26];
char a[G], b[G];

int main() {
	long long n, m;
	cin >> n >> m;
	scanf("%s%s", a, b);
	long long la = strlen(a), lb = strlen(b);
	long long g = __gcd(la, lb), lcm = la * lb / g;
	long long cnt = n * la / lcm;
	long long ans = 0;
	for (int type = 0; type < g; ++type) {
		memset(mem, 0, sizeof(mem));
		for (int i = type; i < lb; i += g) {
			mem[b[i] - 'a']++;
		}
		for (int i = type; i < la; i += g) {
			ans += lb / g - mem[a[i] - 'a'];
		}
	}
	cout << ans * cnt << endl;
	return 0;
}