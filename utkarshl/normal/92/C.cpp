#include"stdio.h"
char s2[1000001]={0}, s1[10001]={0};
int next[10001][26];
int main() {
	scanf("%s%s", s1, s2);
	for(int j=0;j<26;j++)next[10000][j]=-1;
	for(int i=9999; i>=0; i--){
		for(int j=0;j<26;j++)
			next[i][j] = next[i+1][j];
		if(s1[i])
			next[i][s1[i]-'a'] = i;
	}
	int num = 1;
	int pos = 0;
	for(int i=0;s2[i];i++) {
		if(next[0][s2[i]-'a'] == -1) {
			num = -1;
			break;
		}
		if(next[pos][s2[i]-'a'] == -1) pos = 0, num++;
		pos = next[pos][s2[i]-'a'] + 1;
	}
	printf("%d\n", num);
}