#include<bits/stdc++.h>

bool flag[10];

int main(){
	int n;
	char ch;
	scanf("%d", &n);
	int cnt = 0;
	getchar();
	for (int i = 0; i < n; ++ i){
		ch = getchar();
		switch (ch){
			case 'R': if (flag[3]){++ cnt; memset(flag, 0, sizeof(flag));} flag[1] = true; break;
			case 'L': if (flag[1]){++ cnt; memset(flag, 0, sizeof(flag));} flag[3] = true; break;
			case 'U': if (flag[2]){++ cnt; memset(flag, 0, sizeof(flag));} flag[0] = true; break;
			case 'D': if (flag[0]){++ cnt; memset(flag, 0, sizeof(flag));} flag[2] = true; break;
		}
	}
	return printf("%d\n", ++ cnt), 0;
}