#include<cstring>
#include<cstdio>
using namespace std;
int cnt[30],odd;
int main() {
	char s[1005];
	scanf("%s",s);
	for (int i=0;i<strlen(s);++i) cnt[s[i]-'a']++;
	for (int i=0;i<26;++i) if (cnt[i]&1) ++odd;
	if (odd==0||odd&1) printf("First\n");
	else printf("Second\n");
	return 0;
}