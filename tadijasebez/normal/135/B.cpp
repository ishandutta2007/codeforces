#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct Point
{
	int x,y;
	inline int operator + (const Point &b) const
	{
		return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	}
} Points[8],Sq[4],Re[4];
bool Collinear(Point p, Point q, Point r)
{
	int o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	return o==0;
}
vector<int> vec;
bool CheckSquare(Point a[])
{
	vec.clear();
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			vec.push_back(a[i]+a[j]);
		}
	}
	sort(vec.begin(),vec.end());
	for(i=0;i<4;i++)
	{
		if(vec[i]!=vec[0]) return false;
	}
	for(i=4;i<6;i++)
	{
		if(vec[0]*2!=vec[i]) return false;
	}
	int k;
	for(i=0;i<4;i++)
		for(j=i+1;j<4;j++)
			for(k=j+1;k<4;k++)
				if(Collinear(a[i],a[j],a[k])) return false;
	if(vec[0]==0) return false;
	return true;
}
bool CheckRectangle(Point a[])
{
	vec.clear();
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			vec.push_back(a[i]+a[j]);
		}
	}
	sort(vec.begin(),vec.end());
	if(vec[0]!=vec[1]) return false;
	if(vec[2]!=vec[3]) return false;
	for(i=4;i<6;i++)
	{
		if(vec[0]+vec[2]!=vec[i]) return false;
	}
	if(vec[0]==0) return false;
	int k;
	for(i=0;i<4;i++)
		for(j=i+1;j<4;j++)
			for(k=j+1;k<4;k++)
				if(Collinear(a[i],a[j],a[k])) return false;
	return true;
}
int Matrix[300][8];
int GoodMatrix[300][8];
int time;
void BuildMatrix()
{
	int i,j;
	for(i=1;i<=256;i++)
	{
		for(j=0;j<8;j++)
		{
			Matrix[i][j]=Matrix[i-1][j];
		}
		Matrix[i][0]++;
		for(j=0;j<7;j++)
		{
			if(Matrix[i][j]==2)
			{
				Matrix[i][j]=0;
				Matrix[i][j+1]++;
			}
		}
		int sum=0;
		for(j=0;j<8;j++) sum+=Matrix[i][j];
		if(sum==4)
		{
			for(j=0;j<8;j++) GoodMatrix[time][j]=Matrix[i][j];
			time++;
		}
	}
}
void solve()
{
	int i,j;
	for(i=0;i<time;i++)
	{
		int s=0,r=0;
		for(j=0;j<8;j++)
		{
			if(GoodMatrix[i][j]==1) Sq[s]=Points[j],s++;
			else Re[r]=Points[j],r++;
		}
		if(CheckSquare(Sq) && CheckRectangle(Re))
		{
			printf("YES\n");
			for(j=0;j<8;j++) if(GoodMatrix[i][j]==1) printf("%i ",j+1);
			printf("\n");
			for(j=0;j<8;j++) if(GoodMatrix[i][j]==0) printf("%i ",j+1);
			printf("\n");
			return;
		}
	}
	printf("NO\n");
}
int main()
{
	int i;
	for(i=0;i<8;i++) scanf("%i %i",&Points[i].x,&Points[i].y);
	BuildMatrix();
	solve();
	return 0;
}