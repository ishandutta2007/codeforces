#include <bits/stdc++.h>
using namespace std;

#define int long long

#define pii pair <int, int> 
#define mp make_pair

const int N = 1e6 + 5;

deque < pii > A, B;

char s[N];
int n, m, x, y, L[N], Cost = 1e9;
long long ans = 0;

void solve(int x) {
	while(x) {
		if(B.size()) {
			int ret = min(B.back().second, x);
			ans += ret * 4; x -= ret;
			if((B.back().second -= ret) == 0) B.pop_back();
		}
		else if(A.size()) {
			int ret = min(A.front().second, x);
			ans += ret * 6; x -= ret;
			if((A.front().second -= ret) == 0) A.pop_front();
		}
		else {
			if(Cost == 1e9) throw;
			ans += x * Cost; x = 0;
		}
	}
}

struct NODE {
	int pos, Len, ty;
	friend bool operator < (NODE a, NODE b) {
		return make_pair(make_pair(a.pos, a.Len), a.ty) < make_pair(make_pair(b.pos, b.Len), b.ty);
	}
};

vector < NODE > Vec;

main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) scanf("%lld", &L[i]), L[i] *= 2;
  scanf("%s", s + 1);
  for(int i = 1; i <= n; ++ i) {
  	if(s[i] == 'L') {
  		solve(L[i]);
	}
	else if(s[i] == 'G') A.push_back(mp(i, L[i])), Cost = min(Cost, 6LL);
	else B.push_back(mp(i, L[i])), Cost = min(Cost, 4LL);
  }
  for(auto V : A) Vec.push_back((NODE){V.first, V.second, 5});
  for(auto V : B) Vec.push_back((NODE){V.first, V.second, 3});
  sort(Vec.begin(), Vec.end());
  int liu = 0;
  for(int i = 0; i < (int) Vec.size(); ++ i) {
  	NODE cur = Vec[i];
  	if(Vec[i].ty == 3) {
  		liu += Vec[i].Len;
	}
	else {
		int ret = min(liu, cur.Len);
		liu -= ret; ans += ret * 4;
		ans += (cur.Len - ret) * 3;
	}
  }
  ans += liu * 2;
  cout << (ans >> 1) << endl;
}