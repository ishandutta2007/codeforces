#include<cstdio>
#include<cmath>
using namespace std;
const double Pi=acos(-1.0);
double R,alpha;
int n;
int main()
{
	scanf("%d%lf",&n,&R);
	alpha=Pi/n;
	printf("%.10lf\n",R*sin(alpha)/(1-sin(alpha)));
	return 0;
}