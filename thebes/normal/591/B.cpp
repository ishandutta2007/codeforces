#include <bits/stdc++.h>
using namespace std;

int p[30], a[30], n, m, i;
string s; char x, y;

int main(){
	for(i=0;i<26;i++) p[i]=i,a[i]=i;
	cin >> n >> m >> s;
	for(i=0;i<m;i++){
		scanf(" %c %c",&x,&y);
		int l = x-'a', r = y-'a';
		swap(p[a[l]], p[a[r]]);
		swap(a[l], a[r]);
	}
	for(i=0;i<s.size();i++)
		printf("%c",'a'+p[s[i]-'a']);
	return 0;
}