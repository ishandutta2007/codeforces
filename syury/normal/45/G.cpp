#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = 6001;

bool good[N * (N + 1)/2];
int n, S;
bool used[N];

void try_two(int l, int r){
	if(l > r)swap(l, r);
	fill(used, used + n + 1, 1);
	DF(i, n, 1){
		if(l >= i){used[i] = 0; l -= i;}
	}
	if(l)return;
	F(i, 1, n + 1){
		if(used[i])cout << 1;
		else cout << 2;
		cout << ' ';
	}
	exit(0);
}

void try_three(int l, int r){
	if(l > r)swap(l, r);
	fill(used, used + n + 1, 1);
	used[3] = 0;
	DF(i, n, 1){
		if(l >= i){used[i] = 0; l -= i;}
	}
	if(l)return;
	F(i, 1, n + 1){
		if(i == 3){cout << "3 "; cont;}
		if(used[i])cout << 1;
		else cout << 2;
		cout << ' ';
	}
	exit(0);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n == 2){cout << "1 1"; return 0;}
	S = n * (n + 1)/2;
	fill(good, good + S + 1, true);
	good[1] = 0;
	F(i, 2, n + 1){
		if(!good[i])continue;
		for(int j = i + i; j <= S; j += i)
			good[j] = 0;
	}
	F(i, 2, S){
		if(good[i] && good[S - i])
			try_two(i, S - i);
	}
	F(i, 2, S - 3){
		if(good[i] && good[S - 3 - i])
			try_three(i, S - 3 - i);
	}
	assert(0);
	return 0;
}