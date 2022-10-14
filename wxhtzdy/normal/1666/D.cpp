#include <bits/stdc++.h>
using namespace std;
int _,tk[35];
char s[35],t[35];
vector<int> pos[26];
bool solve() {
	scanf("%s\n",s);
	scanf("%s",t);
	int n=strlen(s),m=strlen(t);
	for (int i=0;i<26;i++) pos[i].clear();
	for (int i=0;i<n;i++) pos[s[i]-'A'].push_back(i),tk[i]=0;
	vector<int> cnt(26);
	for (int i=0;i<m;i++) cnt[t[i]-'A']++;
	for (int i=0;i<26;i++) {
		if (cnt[i]>pos[i].size()) return false;
		for (int j=0;j<cnt[i];j++) tk[pos[i][pos[i].size()-j-1]]=1;
	}
	int ptr=0;
	for (int i=0;i<n;i++)if (tk[i]) if (s[i]!=t[ptr++]) return false;
	return ptr==m;
}
int main() {
	for(scanf("%i",&_);_;_--) {
		puts(solve()?"YES":"NO");
	}
	return 0;
}