#include <bits/stdc++.h>
using namespace std;

int h,w,x,y;
bool has[513][513];
char s[100013];

int main() {
	scanf("%d%d%d%d %s",&h,&w,&x,&y,&s);
	int num = 0;
	for (int i=0;s[i]!='\0';i++) {
		if (!has[x][y]) printf("1 "), num+=1;
		else printf("0 ");
		has[x][y] = 1;
		if (s[i]=='L' && y>1) y-=1;
		if (s[i]=='R' && y<w) y+=1;
		if (s[i]=='U' && x>1) x-=1;
		if (s[i]=='D' && x<h) x+=1;
	}
	printf("%d\n",h*w-num);

	return 0;
}