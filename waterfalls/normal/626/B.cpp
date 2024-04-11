#include <bits/stdc++.h>
using namespace std;

int n;
bool can[213][213][213];
int cnt[3];

inline void go(int a, int b, int c) {
	if (can[a][b][c]) return;
	can[a][b][c] = 1;
	if (a && b) go(a-1,b-1,c+1);
	if (b && c) go(a+1,b-1,c-1);
	if (c && a) go(a-1,b+1,c-1);
	if (a>=2) go(a-1,b,c);
	if (b>=2) go(a,b-1,c);
	if (c>=2) go(a,b,c-1);
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char c;
		scanf(" %c",&c);
		if (c=='B') cnt[0]+=1;
		if (c=='G') cnt[1]+=1;
		if (c=='R') cnt[2]+=1;
	}
	go(cnt[0],cnt[1],cnt[2]);
	if (can[1][0][0]) printf("B");
	if (can[0][1][0]) printf("G");
	if (can[0][0][1]) printf("R");
	printf("\n");

	return 0;
}