#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

set<int> hsh;
int n, i, x, y, cnt[30], j;
string s;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		cin >> s;
		memset(cnt,0,sizeof(cnt));
		for(char c : s) cnt[c-'a']++;
		int wts = 1;
		for(j=0;j<26;j++) wts=wts*2+(bool)(cnt[j]);
		hsh.insert(wts);
	}
	printf("%d\n",hsh.size());
	return 0;
}