#include<bits/stdc++.h>

const int N = 300;

char s[N];
int cnt[N], n;

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	int len = strlen(s);
	if (len % 4){
		return printf("===\n"), 0;
	}
	for (int i = 0; i < len; ++ i){
		++ cnt[s[i]];
	}
	if (cnt['A'] > len / 4 || cnt['C'] > len / 4 || cnt['T'] > len / 4 || cnt['G'] > len / 4)
		return printf("===\n"), 0;
	for (int i = 0; i < len; ++ i){
		if (s[i] != '?')
			continue;
		if (cnt['A'] < len / 4){
			s[i] = 'A';
			++ cnt['A'];
			continue;
		}
		if (cnt['T'] < len / 4){
			s[i] = 'T';
			++ cnt['T'];
			continue;
		}
		if (cnt['C'] < len / 4){
			s[i] = 'C';
			++ cnt['C'];
			continue;
		}
		if (cnt['G'] < len / 4){
			s[i] = 'G';
			++ cnt['G'];
		}
	}
	return printf("%s\n", s), 0;
}