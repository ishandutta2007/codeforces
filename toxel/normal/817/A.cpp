#include<bits/stdc++.h>

int x1, y1, x2, y2, x, y;

int main(){
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y);
	int dx = x2 - x1, dy = y2 - y1;
	if (dx % x || dy % y){
		return printf("NO\n"), 0;
	}
	int ansx = dx / x, ansy = dy / y;
	return printf((ansx & 1) == (ansy & 1) ? "YES\n" : "NO\n"), 0;
}