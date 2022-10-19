#include <bits/stdc++.h>
using namespace std;

const int N = 211111;

int ch[N][26] , n , m , x , y , sz , ans , vis[N] , len[N];

char s[N];

queue <int> q;

int dis[N];

multiset <int> S[N];

void dfs(int x) {
  S[x].clear();
  for(int i = 0;i < 26;++ i) {
    int now = ch[x][i];
    if(!now)
      continue;
    dfs(now);
    if(S[now].size() > S[x].size()) {
      swap(S[now] , S[x]);
    }
    for(auto it : S[now]) {
      S[x].insert(it);
    }
  }
  if(x == 1) {
    return;
  }
  if(vis[x]) {
    S[x].insert(dis[x]);
  }
  else {
    int now = *S[x].rbegin();
    S[x].erase(-- S[x].end());
    S[x].insert(dis[x]);
  }
}

main(void) {
	scanf("%d" , &n);
	++ sz;
	for(int i = 1;i <= n;++ i) {
		scanf("%s" , s + 1);
		int l = strlen(s + 1);
		len[i] = l;
		int now = 1;
		for(int j = 1;j <= l;++ j) {
			if(!ch[now][s[j] - 'a']) {
				ch[now][s[j] - 'a'] = ++ sz;
			}
			now = ch[now][s[j] - 'a'];
			dis[now] = j;
		}
		vis[now] = 1;
	}
	dfs(1);
	int ans = 0;
	for(auto V : S[1]) {
	  ans += V;
	}
	cout << ans << endl;
}