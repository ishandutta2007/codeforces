#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int abs(int a){ return a<0?-a:a;}
struct Point
{
	int x,y,i;
	inline bool operator < (const Point &b) const
	{
		if(y==b.y) return x<b.x;
		return y<b.y;
	}
	inline int operator + (const Point &b) const
	{
		return abs(y-b.y)+abs(x-b.x);
	}
	Point (){}
	Point (int a, int b, int in)
	{
		x=a;
		y=b;
		i=in;
	}
};
bool Compare(Point a, Point b)
{
	if(a<b) return false;
	return true;
}
vector<Point> bucket[1005];
vector<Point> Points;
int main()
{
	int n,i,x,y,j;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i %i",&x,&y);
		bucket[x/1000].push_back(Point(x,y,i+1));
	}
	for(i=0;i<=1000;i++)
	{
		if(i%2==0) sort(bucket[i].begin(),bucket[i].end());
		else sort(bucket[i].begin(),bucket[i].end(),Compare);
		for(j=0;j<bucket[i].size();j++) printf("%i ",bucket[i][j].i);
	}
	printf("\n");
	return 0;
}