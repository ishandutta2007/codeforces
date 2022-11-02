#include <bits/stdc++.h>
using namespace std;

int n;
char buff[26];
int from[26], to[26];
bool has[26];

int main() {
	scanf("%d",&n);
	fill(from,from+26,-1);
	fill(to,to+26,-1);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		for (int i=0;buff[i]!='\0';i++) {
			has[buff[i]-'a'] = 1;
			if (i) {
				to[buff[i-1]-'a'] = buff[i]-'a';
				from[buff[i]-'a'] = buff[i-1]-'a';
			}
		}
	}
	for (int i=0;i<26;i++) if (has[i] && from[i]==-1) {
		int j = i;
		while (j!=-1) {
			printf("%c",j+'a');
			j = to[j];
		}
	}
	printf("\n");

	return 0;
}