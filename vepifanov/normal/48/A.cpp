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

bool beat (string a, string b) {
	if (a == "rock" && b == "scissors") re true;
	if (a == "scissors" && b == "paper") re true;
	if (a == "paper" && b == "rock") re true;
	re false;
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	if (beat (a, b) && beat (a, c)) cout << "F"; else
	if (beat (b, a) && beat (b, c)) cout << "M"; else
	if (beat (c, a) && beat (c, b)) cout << "S"; else cout << "?";
	cout << endl;
		                 
	return 0;
}