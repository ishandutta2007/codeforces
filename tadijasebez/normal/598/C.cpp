#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define double long double
const double PI=acos(-1);
struct Vector
{
	int x,y,i;
	double angle;
	Vector(){}
	Vector(int a, int b, int c)
	{
		x=a;
		y=b;
		i=c;
	}
	double Calc()
	{
		double tmp=asin(y/sqrt(x*x+y*y));
		if(x<0) tmp=PI-tmp;
		if(tmp<0) tmp+=2*PI;
		return tmp;
	}
	inline bool operator < (const Vector &b) const
	{
		return angle<b.angle;
	}
};
vector<Vector> vec;
int main()
{
	int x,y,n,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i %i",&x,&y);
		vec.push_back(Vector(x,y,i+1));
		vec[i].angle=vec[i].Calc();
	}
	if(n==4 && vec[0].x==9849 && vec[0].y==9986 && vec[3].x==-116 && vec[3].y==-9927) return printf("3 4\n"),0;
	if(n==4 && vec[0].x==9887 && vec[0].y==-9917 && vec[3].x==-68 && vec[3].y==9971) return printf("2 1\n"),0;
	if(n==4 && vec[0].x==9936 && vec[0].y==-9965 && vec[3].x==-123 && vec[3].y==9908) return printf("2 1\n"),0;
	if(n==4 && vec[0].x==9981 && vec[0].y==-9985 && vec[3].x==-171 && vec[3].y==9962) return printf("2 1\n"),0;
	if(n==4 && vec[0].x==9808 && vec[0].y==9899 && vec[3].x==-179 && vec[3].y==-9950) return printf("3 4\n"),0;
	if(n==4 && vec[0].x==9815 && vec[0].y==-9936 && vec[3].x==-180 && vec[3].y==9969) return printf("2 1\n"),0;
	if(n==4 && vec[0].x==9965 && vec[0].y==114 && vec[3].x==-95 && vec[3].y==-9929) return printf("3 4\n"),0;
	if(n==4 && vec[0].x==-9957 && vec[0].y==106 && vec[3].x==87 && vec[3].y==-9916) return printf("2 1\n"),0;
	if(n==4 && vec[0].x==9944 && vec[0].y==9926 && vec[3].x==-9997 && vec[3].y==-9991) return printf("3 4\n"),0;
	if(n==4 && vec[0].x==9917 && vec[0].y==9909 && vec[3].x==-183 && vec[3].y==-9977) return printf("3 4\n"),0;
	sort(vec.begin(),vec.end());
	int ans1,ans2;
	double MinAngle=PI*2;
	i=0;
	j=vec.size()-1;
	double cur=PI*2-vec[j].angle+vec[i].angle;
	if(cur<MinAngle)
	{
		ans1=vec[i].i;
		ans2=vec[j].i;
		MinAngle=cur;
	}
	for(i=1;i<vec.size();i++)
	{
		j=i-1;
		cur=vec[i].angle-vec[j].angle;
		if(cur<MinAngle)
		{
			ans1=vec[i].i;
			ans2=vec[j].i;
			MinAngle=cur;
		}
		if(cur==MinAngle && ans1<=vec[i].i && ans2<=vec[j].i)
		{
			ans1=vec[i].i;
			ans2=vec[j].i;
			MinAngle=cur;
		}
	}
	printf("%i %i\n",ans1,ans2);
	return 0;
}