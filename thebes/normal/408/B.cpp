#include <bits/stdc++.h>
using namespace std;

string s, t;
int cnt[26], a[26], i, ans;

int main(){
	cin >> s;
	for(char c : s)
		cnt[c-'a']++;
	cin >> t;
	for(char c : t)
		a[c-'a']++;
	for(i=0;i<26;i++){
		if(a[i]&&!cnt[i]){printf("-1\n"); return 0;}
		ans += min(a[i],cnt[i]);
	}
	printf("%d\n",ans);
	return 0;
}