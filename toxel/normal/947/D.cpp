#include<bits/stdc++.h>

const int N = 100010;

char s[N], t[N];
int pres[N][2], pret[N][2];

int main(){
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	std::vector <int> vecs, vect;
	for (int i = 1; i <= n; ++ i){
		if (s[i] == 'C'){
			s[i] = 'B';
		}
		if (s[i] == 'B'){
			vecs.push_back(i);
		}
		pres[i][0] = pres[i - 1][0] + (s[i] == 'A');
		pres[i][1] = pres[i - 1][1] + (s[i] == 'B');
	}
	for (int i = 1; i <= m; ++ i){
		if (t[i] == 'C'){
			t[i] = 'B';
		}
		if (t[i] == 'B'){
			vect.push_back(i);
		}
		pret[i][0] = pret[i - 1][0] + (t[i] == 'A');
		pret[i][1] = pret[i - 1][1] + (t[i] == 'B');
	}
	int q;
	scanf("%d", &q);
	while (q --){
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int sit1 = std::upper_bound(vecs.begin(), vecs.end(), r1) - vecs.begin();
		sit1 = sit1 ? vecs[sit1 - 1] : l1 - 1;
		if (sit1 < l1){
			sit1 = l1 - 1;
		}
		int sit2 = std::upper_bound(vect.begin(), vect.end(), r2) - vect.begin();
		sit2 = sit2 ? vect[sit2 - 1] : l2 - 1;
		if (sit2 < l2){
			sit2 = l2 - 1;
		}
		int x = r1 - sit1, y = r2 - sit2;
		if (x < y){
			putchar('0');
			continue;
		}
		if (x == y && sit1 == l1 - 1 && sit2 > l2 - 1){
			putchar('0');
			continue;
		}
		x -= (x - y) / 3 * 3;
		int cnt1 = std::min(1, x - y) * 2;
		cnt1 += pres[sit1][1] - pres[l1 - 1][1];
		int cnt2 = pret[sit2][1] - pret[l2 - 1][1];
		if (cnt1 > cnt2 || (cnt1 - cnt2 & 1)){
			putchar('0');
		}
		else{
			putchar('1');
		}
	}
	putchar('\n');
	return 0;
}