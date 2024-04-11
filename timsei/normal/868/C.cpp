#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N] , num[1 << 16] , n , m , ans , s[4] , h , all[20];

main(void) {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++) {
		int p = 0;
		for(int j = 0;j < m;j ++) {
			scanf("%d",&h);
			p |= (1 << j) * h;
		}
		num[p] ++;
		if(!p) {
			puts("YES"); return 0;
		}
	}
	
	for(int i = 0;i <(1 << m);i ++) if(num[i]){
		for(int j = 0;j < (1 << m);j ++) if((i == j && num[i] >= 2) || (i != j && num[j])){
			memset(s , 0 , sizeof(s));
			bool flag = 0;
			for(int k = 0;k < m;k ++) {
				s[k] += ((i >> k) & 1) + ((j >> k) & 1);
				if(s[k] == 2) flag = 1;
			}
			if(!flag) {
				puts("YES"); return 0;
			}
		}
	}
	puts("NO");
}