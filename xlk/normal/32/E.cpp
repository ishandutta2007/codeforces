#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<complex>
using namespace std;
typedef complex<double> P;
P v, p, w1, w2, m1, m2;
int l, r;
P operator *(const P&D, double C) {
	return P(C, 0) * D;
}
double det(P A, P B) {
	return imag(A * conj(B));
}
double dot(P A, P B) {
	return real(A * conj(B));
}
bool in(P x, P A, P B) {
	return det(A - x, B - x) == 0 && dot(A - x, B - x) <= 0;
}
bool ins(P A, P B, P C, P D) {
	double t1 = det(C - A, B - A) * det(B - A, D - A), t2 = det(A - C, D - C)
			* det(D - C, B - C);
	if (t1 < 0 || t2 < 0)
		return 0;
	if (t1 == 0 && t2 == 0)
		return in(C, A, B) || in(D, A, B);
	else
		return 1;
}
P sym(P x, P A, P B) {
	return x + 2 * dot(A, B) / dot(B, B) * B - A;
}
bool ck() {
	if (ins(v, p, m1, m2))
		return !ins(v, p, w1, w2) && det(m2 - m1, p - v) == 0;
	if (ins(v, p, w1, w2)) {
		P V = sym(m1, v - m1, m2 - m1), P = sym(m1, p - m1, m2 - m1);
		return ins(v, P, m1, m2) && !ins(v, P, w1, w2) && !ins(V, p, w1, w2);
	}
	return 1;
}
void scan(P&A) {
	double x, y;
	scanf("%lf%lf", &x, &y);
	A = P(x, y);
}
int main() {
	scan(v);
	scan(p);
	scan(w1);
	scan(w2);
	scan(m1);
	scan(m2);
	puts(ck() ? "YES" : "NO");
}