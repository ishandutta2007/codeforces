#include<bits/stdc++.h>

const int N = 10;

int n;
char s[N];

int main(){
	scanf("%d", &n);
	int dis = 0;
	bool flag = true;
	while (n --){
		int t;
		scanf("%d%s", &t, s);
		if(dis == 0){
			if (s[0] != 'S'){
				flag = false;
			}
		}
		if (dis == 20000){
			if (s[0] != 'N'){
				flag = false;
			}
		}
		if (s[0] == 'S')
			dis += t;
		if (s[0] == 'N')
			dis -= t;
		if (dis > 20000 || dis < 0)
			flag = false;
	}
	if (dis)
		flag = false;
	return printf(flag ? "Yes\n" : "No\n"), 0;
}