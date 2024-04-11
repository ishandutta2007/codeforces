#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
int a1, b1, c1;
int a2, b2, c2;
int d1, d2, d3, d4, d5, d6, d7;

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d", &a2, &b2, &c2);
		scanf ("%d%d%d", &a1, &b1, &c1);
		scanf ("%d%d%d%d%d%d%d", &d1, &d2, &d3, &d4, &d5, &d6, &d7);
		int A1 = max (0, (d1 + d2 + d3 + d4) - a1);
		int B1 = max (0, (d1 + d2 + d5 + d6) - b1);
		int C1 = max (0, (d1 + d3 + d5 + d7) - c1);
		int ok = 0;
		int p1, p2, p3, p4, p5, p6, p7;
//		printf ("%d %d %d\n", A1, B1, C1);
//		printf ("%d %d | %d %d | %d %d\n", A1, a2, B1, b2, C1, c2);
		if (A1 <= a2 && B1 <= b2 && C1 <= c2)
		for (int f1 = 0; f1 <= d1 && !ok; f1++)
			for (int f2 = 0; f2 <= d2 && !ok; f2++) {
				int l3 = max (0, A1 - d4 - f1 - f2);
				int r3 = min (d3, a2 - f1 - f2);
				int l5 = max (0, B1 - d6 - f1 - f2);
				int r5 = min (d5, b2 - f1 - f2);
				int l35 = max (0, C1 - d7 - f1);
				int r35 = c2 - f1;
				if (l3 <= r3 && l5 <= r5 && l35 <= r35 && max (l3 + l5, l35) <= min (r3 + r5, r35)) {
					int s35 = max (l3 + l5, l35);
					if (l3 + r5 >= s35) {
						p3 = l3;
						p5 = s35 - p3;
					} else {
						p5 = r5;
						p3 = s35 - p5;
					}
					p1 = f1;
					p2 = f2;
					p4 = max (0, A1 - p1 - p2 - p3);
                    p6 = max (0, B1 - p1 - p2 - p5);
                    p7 = max (0, C1 - p1 - p3 - p5);
                    ok = 1;
//                    printf ("%d %d\n", f1, f2);
//                    printf ("%d <= %d <= %d\n", l3, p3, r3);
//                    printf ("%d <= %d <= %d\n", l5, p5, r5);
//                    printf ("%d <= %d <= %d\n", l35, s35, r35);
				}
			}
		if (!ok) printf ("-1\n"); else {
			printf ("%d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7);
/*			printf ("%d <= %d <= %d\n", 0, p1, d1);
			printf ("%d <= %d <= %d\n", 0, p2, d2);
			printf ("%d <= %d <= %d\n", 0, p3, d3);
			printf ("%d <= %d <= %d\n", 0, p4, d4);
			printf ("%d <= %d <= %d\n", 0, p5, d5);
			printf ("%d <= %d <= %d\n", 0, p6, d6);
			printf ("%d <= %d <= %d\n", 0, p7, d7);
			printf ("%d <= %d\n", p1 + p2 + p3 + p4, a2);
			printf ("%d <= %d\n", (d1 - p1) + (d2 - p2) + (d3 - p3) + (d4 - p4), a1);
			printf ("%d <= %d\n", p1 + p2 + p5 + p6, b2);
			printf ("%d <= %d\n", (d1 - p1) + (d2 - p2) + (d5 - p5) + (d6 - p6), b1);
			printf ("%d <= %d\n", p1 + p3 + p5 + p7, c2);
			printf ("%d <= %d\n", (d1 - p1) + (d3 - p3) + (d5 - p5) + (d7 - p7), c1);*/
		}
	}
	re 0;
}