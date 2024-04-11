#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int area = 0;
	int minx = 32000, maxx = -1, miny = 32000, maxy = -1;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		area += (x2 - x1) * (y2 - y1);
		minx = min(minx, x1);
		maxx = max(maxx, x2);
		miny = min(miny, y1);
		maxy = max(maxy, y2);
	}
	if (maxx - minx == maxy - miny && area == (maxx - minx) * (maxx - minx))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}