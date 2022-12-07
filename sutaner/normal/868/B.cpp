#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define eps 1e-6
using namespace std;

bool cmp(double x, double y){
	return y - x > eps;
}

double line[10];

int main(){
	int h, m, s, t1, t2;
	scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
	
	double p1 = ((h * 3600 + m * 60 + s) % 43200) / 43200.0;
	double p2 = ((m * 60 + s) % 3600) / 3600.0;
	double p3 = ((s % 60)) / 60.0;
	
	double x = ((t1 * 3600) % 43200) / 43200.0;
	double y = ((t2 * 3600) % 43200) / 43200.0;
	
	if (x - y > eps) swap(x, y);
	
	line[0] = p1;
	line[1] = p2;
	line[2] = p3;
	
	sort(line, line + 3);
	int a = lower_bound(line, line + 3, x) - line;
	int b = lower_bound(line, line + 3, y) - line;
	if (a == b || ((line[0] - x > eps) && (y - line[2] > eps))) printf("YES");
	else printf("NO");
	return 0;
}