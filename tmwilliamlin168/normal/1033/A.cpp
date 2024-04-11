#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

int n, ax, ay, bx, by, cx, cy;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
	cout << ((bx>ax)==(cx>ax)&&(by>ay)==(cy>ay)?"YES":"NO");
}