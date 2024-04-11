#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld x1,y1,r1;
ld x2,y2,r2;

ld sq(ld x) { return x*x; }

void quit() { printf("0\n"), exit(0); }

int main() {
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	ld d = sqrt(sq(x2-x1)+sq(y2-y1));
	if (d+r1<=r2+1e-15) return printf("%1.12f\n",(double) (2*acos(0.0)*sq(r1))), 0;
	if (d+r2<=r1+1e-15) return printf("%1.12f\n",(double) (2*acos(0.0)*sq(r2))), 0;
	if (d>r1+r2) quit();

	ld one = (sq(d)+sq(r1)-sq(r2))/(2*d*r1);
	if (one<-1 || one>1) quit();
	one = sq(r1)*(acos(one)-one*sin(acos(one)));

	ld two = (sq(d)+sq(r2)-sq(r1))/(2*d*r2);
	if (two<-1 || two>1) quit();
	two = sq(r2)*(acos(two)-two*sin(acos(two)));

	printf("%1.12f\n",(double) (one+two));

	return 0;
}