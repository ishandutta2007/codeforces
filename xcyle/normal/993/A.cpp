#include <iostream>
#include <cstdio>
using namespace std;
double ax[10], ay[10], bx[10], by[10];
double Abs(double t)
{
	return t > 0 ? t : -t; 
}
int main()
{
	double lx = 200.0, rx = -200.0, ly = 200.0, ry = -200.0;
	for (int i = 1; i <= 4; i++)
	{
		scanf("%lf%lf", &ax[i], &ay[i]);
		lx = min(lx, ax[i]), rx = max(rx, ax[i]);
		ly = min(ly, ay[i]), ry = max(ry, ay[i]);
	}
	double tx = 0, ty = 0;
	for (int i = 1; i <= 4; i++)
	{
		scanf("%lf%lf", &bx[i], &by[i]);
		tx += bx[i], ty += by[i];
	}
	tx /= 4, ty /= 4;
	double r = Abs(bx[1] - tx) + Abs(by[1] - ty);
	double ansx, ansy;
	if(lx <= tx && tx <= rx) ansx = 0;
	else ansx = min(Abs(lx - tx), Abs(rx - tx));
	if(ly <= ty && ty <= ry) ansy = 0;
	else ansy = min(Abs(ly - ty), Abs(ry - ty));
	if(ansx + ansy <= r) printf("YES");
	else printf("NO");
	return 0;
}