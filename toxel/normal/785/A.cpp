#include<bits/stdc++.h>

const int N = 20;

char s[N];
int n;

int main(){
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%s", s);
		switch (s[0]){
			case 'T' : sum += 4; break;
			case 'C' : sum += 6; break;
			case 'O' : sum += 8; break;
			case 'D' : sum += 12; break;
			case 'I' : sum += 20; break;
		}
	}
	return printf("%d\n", sum), 0;
}