#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int x[1000001];
int y[1000001];

typedef long double ld;

ld length(ld x, ld y)
{
    return x * x + y * y;
}

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    ld dx = x2 - x1, dy = y2 - y1;
    ld a = 0, b = 1;
    for(int i = 0; i < 200; i++)
    {
	ld c = (a + a + b) / 3, d = (a + b + b) / 3;
	if(length(x1 + c * dx, y1 + c * dy) > length(x1 + d * dx, y1 + d * dy))
	    a = c;
	else b = d;
    }
    a = (a + b) / 2;
    return length(x1 + a * dx, y1 + a * dy);
}

int main()
{
    int n, px, py;
    cin >> n >> px >> py;
    ld mx = 0, mn = 1e15;
    for(int i = 0; i < n; i++)
    {
	cin >> x[i] >> y[i];
	x[i] -= px;
	y[i] -= py;
	mx = max(mx, length(x[i], y[i]));
    }
    x[n] = x[0];
    y[n] = y[0];
    for(int i = 0; i < n; i++)
	mn = min(mn, dist(x[i], y[i], x[i+1], y[i+1]));
    
    ld pi = 3.141592653589793116;
    cout << setprecision(15) << pi * (mx - mn) << "\n";
}