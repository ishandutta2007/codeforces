#include <bits/stdc++.h>
using namespace std;

int n,c;
int p[1013], t[1013];

int score() {
	int res = 0;
	int curt = 0;
	for (int i=0;i<n;i++) {
		curt+=t[i];
		res+=max(0,p[i]-c*curt);
	}
	return res;
}

int main() {
	scanf("%d%d",&n,&c);
	for (int i=0;i<n;i++) scanf("%d",&p[i]);
	for (int i=0;i<n;i++) scanf("%d",&t[i]);
	int limak = score();
	reverse(p,p+n);
	reverse(t,t+n);
	int rade = score();
	if (limak==rade) printf("Tie\n");
	if (limak>rade) printf("Limak\n");
	if (limak<rade) printf("Radewoosh\n");

	return 0;
}