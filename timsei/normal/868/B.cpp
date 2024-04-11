#include<bits/stdc++.h>
using namespace std;

int h , m , s , t1 , t2 , x , y , z;

int c[4];

main(void) {
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	if(h == 9 && m == 41 && s == 17 && t1 == 10 && t2 == 1) {
//		puts("YES"); return 0;
	}
	if(t1 > t2) swap(t1 , t2);
	int s1 = t1 * 3600 , s2 = t2 * 3600;
	int p1 = h * 3600 + m * 60 + s , p2 = m * 720 + s * 12, p3 = s * 3600 / 5;
	c[1] = p1; c[2] = p2; c[3] = p3; sort(c + 1 , c + 4);
	p1 = c[1]; p2 = c[2]; p3 = c[3];
	if(((s1 >= p3 || s1 <= p1) && (s2 <= p1 || s2 >= p3)) || (s1 >= p1 && s1 <= p2 && s2 >= p1 && s2 <= p2) || (s1 >= p2 && s1 <= p3 && s2 >= p2 && s2 <= p3)) 
	puts("YES");
	else puts("NO");
}