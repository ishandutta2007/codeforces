#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair


int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int ans = 0;
    int n;
	ll wd = 0;
    string s, s1;
    cin >> n;
	vll h(n), w(n), hs(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
		hs[i] = h[i];
		wd += w[i];
	}
	sort(all(hs));
	for (int i = 0; i < n; i++) {
		ll hcur = hs[n-1];
		if (h[i] == hs[n-1]) {
			hcur = hs[n-2];
		}
		cout << hcur * (wd - w[i]) << " ";
	}

}