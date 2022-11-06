#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e2 + 10;

int N, Nr[MAX_N];

int main() {
	cin >> N;
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	bool isGood = true;
	for(int i=1; i<N; i++) if(Nr[i] - Nr[i-1] != Nr[1] - Nr[0]) isGood = false;
	if(isGood) printf("%d\n", Nr[N-1] + Nr[1] - Nr[0]);
	else printf("%d\n", Nr[N-1]);
	return 0;
}