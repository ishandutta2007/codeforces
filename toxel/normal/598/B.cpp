#include<bits/stdc++.h>

const int N = 10010;

char s[N], _s[N];

int main(){
	scanf("%s", s);
	int len = strlen(s), m;
	scanf("%d", &m);
	while (m --){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		-- l, -- r;
		for (int i = l; i <= r; ++ i){
			int sit = (i - l - k) % (r - l + 1);
			sit = (sit + r - l + 1) % (r - l + 1);
			sit += l;
			_s[i] = s[sit];
		}
		for (int i = l; i <= r; ++ i){
			s[i] = _s[i];
		}
	}
	return printf("%s\n", s), 0;
}