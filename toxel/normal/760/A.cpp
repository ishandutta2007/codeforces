#include<bits/stdc++.h>

int month, day, orz[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	scanf("%d%d", &month, &day);
	-- day;
	int cnt = 1;
	for (int i = 0; i < orz[month - 1] - 1; ++ i){
		day = (day + 1) % 7;
		if (!day){
			++ cnt;
		}
	}
	return printf("%d\n", cnt), 0;
}