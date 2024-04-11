#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;

char w[100];
map<string, int> all;
int sum[1000], ai[1000], aj[1000], can[1000], r;
string sname[1000];

int get (string s) {
	if (all.find (s) == all.end ()) {
		all[s] = r;
		sname[r] = s;
		sum[r] = 0;
		r++;
	}
	return all[s];
}

int main() {
        int n;
        r = 0;
        scanf ("%d\n", &n);
        for (int i = 0; i < n; i++) {
        	gets (w);
        	stringstream in (w);
        	string name;
        	int score;
        	in >> name >> score;
        	int num = get (name);
        	sum[num] += score;
        	ai[i] = num;
        	aj[i] = score;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        	if (sum[i] > res)
        		res = sum[i];
        for (int i = 0; i < n; i++)
        	if (sum[i] == res)
        		can[i] = 1;
        memset (sum, 0, sizeof (sum));
        for (int i = 0; i < n; i++) {
        	int num = ai[i];
        	int score = aj[i];
        	sum[num] += score;
        	if (sum[num] >= res && can[num]) {
        		cout << sname[num] << endl;
        		return 0;
        	}
        }
	return 0;
}