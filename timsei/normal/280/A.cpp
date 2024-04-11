#include <bits/stdc++.h>
using namespace std;

double w , h , x;

const double pi = acos(-1);

int main(void) {
    cin >> w >> h >> x;
    if(w < h) {
	swap(w , h);
    }
    if(x > 90) x = 180 - x;
    if(fabs(x) < 1e-9) {
	printf("%.55000000lf\n" , w * h);
	return  0;
    }
    if(fabs(x - 90) < 1e-9) {
	printf("%.55000000lf\n" , min(w , h) * min(w , h));
	return 0;
    }
    x = x / 180 * pi;
    double wev = w * w / h / h;
    wev = (wev - 1) / (1 + wev);
    double it = acos(wev);
     if(x < it) {
	double a = (h * sin(x) - w - w * cos(x)) / (sin(x) * sin(x) - (1 + cos(x)) * (1 + cos(x)));
	double ans = h * w;
	ans -= a * a * cos(x) * sin(x);
	double A = w - a - a * cos(x);
	A = A / sin(x);
	ans -= A * A * cos(x) * sin(x);
	printf("%.55000000lf\n" , ans);
    }
    else {
	printf("%.55000000lf\n" , h / sin(x) * h);
    }
}