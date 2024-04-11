#include <bits/stdc++.h>
using namespace std;

int score[5] = {500,1000,1500,2000,2500};
int m[5];
int w[5];
int h[2];

int main() {
	for (int i=0;i<5;i++) cin >> m[i];
	for (int i=0;i<5;i++) cin >> w[i];
	cin >> h[0] >> h[1];
	int ans = 0;
	for (int i=0;i<5;i++) ans+=max(score[i]*3/10,score[i]-score[i]/250*m[i]-50*w[i]);
	ans+=100*h[0];
	ans-=50*h[1];
	cout << ans << '\n';

	return 0;
}