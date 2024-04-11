#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9+9;

int N;
string s, cur;

#define MAXN 1000010

int n, m, r[MAXN];

void preprocessPattern() {
	r[0] = -1;
	for (int i = 0, j = -1; i < min(sz(cur), sz(s)); i++) {
		while (j >= 0 && cur[i] != cur[j])
			j = r[j];
		r[i + 1] = ++j;
	}
}

// get the indices of matches from p in s
int findMatches() {
	n = m = min(sz(cur), sz(s));
  int of = max(0, sz(s)-sz(cur));
	for (int i = 0, j = 0; i < n; i++) {
		while (j >= 0 && s[of+i] != cur[j])
			j = r[j];
		j++;
    if(i == n-1)
      return j;
    /*
		if (j == m){
			//res.push_back(i - j + 1), j = r[j];
      return 
      j = r[j];
    }
    */
	}
	return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  cin >> s;
  for(int i=1; i<N; i++){
    cin >> cur;
    preprocessPattern();
    int m = findMatches();
    for(int i=m; i<sz(cur); i++){
      s.push_back(cur[i]);
    }
  }
  cout << s << endl;

  return 0;
}