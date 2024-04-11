#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define INF 1000000000

#define MAX(x,y) (x)>(y)?(x):(y)

#define N 500500

using namespace std;

int n,x[N],y[N];
long long ans;

long long way(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3){
	return (y2-y1)*(x3-x1)+(x1-x2)*(y3-y1);
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++){
			long long s1=-1,s2=-1;
			for (int k=0;k<n;k++)
				if ((k!=i)&&(k!=j)){
					long long r=abs((y[i]-y[j])*(x[i]+x[j])+(y[j]-y[k])*(x[j]+x[k])+(y[k]-y[i])*(x[i]+x[k]));
					if (way(x[i],y[i],x[j],y[j],x[k],y[k])<0)s1=MAX(s1,r);else s2=MAX(s2,r);
				}
			if ((s1<0)||(s2<0))continue;
			ans=MAX(ans,s1+s2);
		}
	printf("%.10lf\n",ans*0.5);
}