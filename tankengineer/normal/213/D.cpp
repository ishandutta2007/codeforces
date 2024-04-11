#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double pi = 3.14159265358979323846264338327950288;

int n, m;
int  t[505], p[505], s[105][6];
double l, x[6], y[6], px[505], py[505];

int main() {
	l = 10.0 / sin(36.0 / 180.0 * pi) * sin(108.0 / 180.0 * pi);
	x[1] = l * cos(72.0 / 180.0 * pi);
	y[1] = l * sin(72.0 / 180.0 * pi);
	x[2] = x[1];
	y[2] = -y[1];
	x[3] = -l * cos(36.0 / 180.0 * pi);
	y[3] = l * sin(36.0 / 180.0 * pi);
	x[4] = l;
	y[4] = 0;
	x[5] = x[3];
	y[5] = -y[3];
	
	scanf("%d", &n);
	s[0][3] = 1;
	int cnt = 5 + (n - 1) * 4;
	for (int i = 1; i <= n; ++i) {
	  s[i][1] = s[i - 1][3];
	  s[i][2] = s[i][1] + 1;
	  s[i][3] = s[i][2] + 1;
	  s[i][5] = cnt--;
	  s[i][4] = cnt--;
	}
	int top = 2 * n + 1;
	for (int i = 1; i <= 2 * n + 1; ++i) t[i] = i;
	for (int i = n; i >= 1; --i) {
		t[++top] = s[i][4];
		t[++top] = s[i][5];
		t[++top] = s[i][1];
	}
	p[1] = 1;
  for (int i = 2; i <= n; ++i) {
	  p[i * 2 - 2] = 2 - i % 2;
	  p[i * 2 - 1] = p[i * 2 - 2];
	}
	p[n * 2] = 2 - (n + 1) % 2;
	for (int i = 1; i <= n; ++i) {
		if ((n - i + 1) % 2) {
		  p[n * 2 + (i - 1) * 3 + 1] = 3;
		  p[n * 2 + (i - 1) * 3 + 2] = 4;
	  	p[n * 2 + (i - 1) * 3 + 3] = 5;	  
		} else {
		  p[n * 2 + (i - 1) * 3 + 1] = 5;
		  p[n * 2 + (i - 1) * 3 + 2] = 4;
	  	p[n * 2 + (i - 1) * 3 + 3] = 3;	  
		}
	}
	//for (int i = 1; i <= n * 5; ++i) printf("%d ", p[i]);
	double tx = 0, ty = 0;
	for (int i = 1; i <= n * 5; ++i) {
	  px[t[i]] = tx;
	  py[t[i]] = ty;
	  tx += x[p[i]];
	  ty += y[p[i]];
	}
	int m = 5 + (n - 1) * 4;
	printf("%d\n", m);
	for (int i = 1; i <= m; ++i) printf("%.12lf %.12lf\n", px[i], py[i]);
	for (int i = 1; i <= n; ++i) printf("%d %d %d %d %d\n", s[i][1], s[i][4], s[i][2], s[i][5], s[i][3]);
	for (int i = 1; i < top; ++i) printf("%d ", t[i]);
	printf("%d\n", t[top]);
	return 0;
}