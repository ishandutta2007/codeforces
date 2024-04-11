#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];

int main() {
	cin >> s;
	for (char c: s) cnt[c-'a']+=1;
	int odd = 0;
	for (int i=0;i<26;i++) if (cnt[i]%2==1) odd+=1;
	while (odd!=s.size()%2) {
		int low = 0;
		while (cnt[low]%2==0) low+=1;
		int high = 25;
		while (cnt[high]%2==0) high-=1;
		cnt[low]+=1;
		cnt[high]-=1;
		odd-=2;
	}
	for (int i=0;i<26;i++) for (int j=0;j<cnt[i]/2;j++) printf("%c",i+'a');
	if (s.size()%2==1) {
		int low = 0;
		while (cnt[low]%2==0) low+=1;
		printf("%c",low+'a');
	}
	for (int i=25;i>=0;i--) for (int j=0;j<cnt[i]/2;j++) printf("%c",i+'a');
	printf("\n");

	return 0;
}