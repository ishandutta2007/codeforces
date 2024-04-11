#include<bits/stdc++.h>

const int N = 100010;

char a[N], b[N];
int n;

int main(){
	scanf("%d%s", &n, a);
	int len = strlen(a);
	for (int i = 0, j = 0; i < len; ){
		if ((a[i] == 'a' || a[i] == 'i' || a[i] == 'u' || a[i] == 'y') && a[i] == a[i + 1]){
			++ i;
			continue;
		}
		if (a[i] == 'e' || a[i] == 'o'){
			int cnt = 0;
			while (a[i] == a[i + 1]){
				++ cnt, ++ i;
			}
			if (cnt > 1){
				cnt = 0;
			}
			for (int k = 0; k <= cnt; ++ k){
				b[j ++] = a[i];
			}
			++ i;
			continue;
		}
		b[j ++] = a[i ++];
	}
	return printf("%s\n", b), 0;
}