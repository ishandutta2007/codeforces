#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
//#define double long double
const double PI=acos(-1);
const int N=100050;
double V[N];
vector<double> id;
int index[N];
double max(double a, double b){ return a>b?a:b;}
double BIT[N];
void Set(int i, double x){ for(;i<N;i+=i&-i) BIT[i]=max(BIT[i],x);}
double Get(int i){ double ret=0;for(;i;i-=i&-i) ret=max(ret,BIT[i]);return ret;}
double sol,ans[N];
int main()
{
	int n,i,r,h;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&r,&h);
		V[i]=PI*r*r*h;
		id.push_back(V[i]);
	}
	sort(id.begin(),id.end());
	for(i=1;i<=n;i++) index[i]=lower_bound(id.begin(),id.end(),V[i])-id.begin()+1;
	for(i=1;i<=n;i++)
	{
		ans[i]=Get(index[i]-1)+V[i];
		sol=max(sol,ans[i]);
		Set(index[i],ans[i]);
	}
	printf("%.12Lf\n",sol);
	return 0;
}