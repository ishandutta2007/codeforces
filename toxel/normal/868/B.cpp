#include<bits/stdc++.h>

int h, m, s, t1, t2;

int main(){
	scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
	h %= 12, t1 %= 12, t2 %= 12;
	int hh = 3600 * 5 * h + 60 * m + s, mm = 3600 * m + 60 * s, ss = s * 3600;
	t1 *= 5 * 3600, t2 *= 5 * 3600;
	if (t1 > t2) std::swap(t1, t2);
	bool flag = true;
	for (int i = t1; i <= t2; ++ i){
		if (i == hh || i == mm || i == ss){
			flag = false;
			break;
		}
	}
	if (flag){
		return printf("YES\n"), 0;
	}
	flag = true;
	for (int i = t2; i < 1000000; ++ i){
		if (i == hh || i == mm || i == ss){
			flag = false;
			break;
		}
	}
	for (int i = 0; i <= t1; ++ i){
		if (i == hh || i == mm || i == ss){
			flag = false;
			break;
		}
	}
	if (flag){
		return printf("YES\n"), 0;
	}
	return printf("NO\n"), 0;
}