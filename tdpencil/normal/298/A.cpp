#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define vt vector
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define cnt count
bool isPal(string &v) {
	int l=0,r=v.size()-1;
	while(l <= r) {
		if(v[l++]!=v[r--]) return 0;
	}
	return 1;
}
char path[1001];
int start, end;
int main() {

	int T = 1;
	while(T--) {
		int N; scanf("%d", &N);
		deque<int> L;
		deque<int> R;
		
		scanf("%s", path);
		bool containsL = false, containsR = false;
		for(int i = 0; i < N; i++) {
			if(path[i]=='.') continue;
			
			if(path[i] == 'R' && ((i == 0 || path[i-1] != 'R') || (i == N-1 || path[i+1] != 'R'))) {
				R.pb(i + 1);
				containsR = true;
			} else if(path[i] == 'L' && ((i == N - 1 || path[i+1] != 'L') || (i == 0 || path[i-1] != 'L'))) {
				L.pb(i + 1);
				containsL = true;
			}
			
		}
		
		if(!containsR) {
			printf("%d %d", L.back(), L.front() - 1);
		} else if(!containsL) {
			printf("%d %d", R.front(), R.back() + 1);
		} else {
			printf("%d %d", R.front(), L.front() - 1);
		}
	}
}