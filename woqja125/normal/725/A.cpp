#include<stdio.h>
#include<string.h>
char in[200001];
int main() {
	int n, c=0;
	scanf("%d%s", &n, in);
	for (int i = 0; i < n && in[i] == '<'; i++) c++;
	for (int i = n - 1; i >= 0 && in[i] == '>'; i--) c++;
	printf("%d", c);
	return 0;
}