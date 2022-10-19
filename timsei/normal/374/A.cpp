#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int x , y , i , j , n , m ,ii , jj , a , b;

int doit(int x , int y) {
	i = ii; j = jj;
	if((x - i) % a != 0|| (y - j) % b != 0) return 2e9;
	int dis1 = abs(x - i) / a , dis2 = abs(y - j) / b;
	int col = min(dis1 , dis2);
	if(x - i < 0) i -= col * a; else i += col * a;
	if(y - j < 0) j -= col * b; else j += col * b;
//	cerr<<x<<" "<<y<<" "<<col<<endl;
	if(i == x && j == y) return col;
	if(i == x) {
		if((abs(j - y) / b) % 2 != 0) return 2e9;
		if(x + a > n && x - a <= 0) return 2e9;
		col += (abs(j - y) / b);
		return col;
	} 
	if(j == y) {
		if((abs(x - i) / a) % 2 != 0) return 2e9;
		if(y + b > m && y - b <= 0) return 2e9;
		col += (abs(x - i) / a);
		return col;
	} 
	return 40012312;
}

int main(void) {
	scanf("%d%d%d%d%d%d",&n,&m,&ii,&jj,&a,&b);
	int ans = 2e9;
	ans = min(ans , doit(n ,m));
	ans = min(ans , doit(n ,1));
	ans = min(ans , doit(1 ,m));
	ans = min(ans , doit(1 ,1));
	if(ans > 1e9) puts("Poor Inna and pony!");
	else cout<<ans<<endl;
}