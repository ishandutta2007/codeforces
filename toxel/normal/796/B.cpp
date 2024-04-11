#include<bits/stdc++.h>

const int N = 1000010;

int n, m, k;
bool exi[N];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0, x; i < m; ++ i){
		scanf("%d", &x);
		exi[x] = true;
	}
	if (exi[1]){
		return printf("1\n"), 0;
	}
	int sit = 1;
	for (int i = 0, u, v; i < k; ++ i){
		scanf("%d%d", &u, &v);
		if (sit == u){
			sit = v;
		}
		else if (sit == v){
			sit = u;
		}
		if (exi[sit]){
			return printf("%d\n", sit), 0;
		}
	}
	return printf("%d\n", sit), 0;
}