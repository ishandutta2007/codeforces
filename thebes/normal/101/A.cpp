#include <bits/stdc++.h>
using namespace std;

int cnt[30], rem[30], n, k, i, j;
pair<int,int> wts[30];
string s;

int main(){
	cin >> s >> k;
	for(char c : s) cnt[c-'a']++;
	for(i=0;i<26;i++) wts[i]={cnt[i],i};
	sort(wts,wts+26);
	for(i=0;i<26;i++){
		k -= wts[i].first;
		if(k>=0) rem[wts[i].second]=1,n++;
	}
	printf("%d\n",26-n);
	for(char c : s)
		if(!rem[c-'a']) putchar(c);
	return 0;
}