#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

double yy[1000];
int n,r,xx[1000];

int _abs(int a) {
	return a<0 ? -a : a;
}
int main() {
	scanf("%d %d",&n,&r);
	for(int i=0;i<n;i++) scanf("%d",xx+i);
	for(int i=0;i<n;i++) {
		int flag=0;
		double y=0;
		for(int j=0;j<i;j++) {
			int dif=_abs(xx[i]-xx[j]);
			if(dif<=2*r) {
				flag=1;
				y=max(y,yy[j] + sqrt(4*r*r-dif*dif));
			}
		}
		if(flag) yy[i]=y;
		else yy[i]=r;
	}
	for(int i=0;i<n;i++) printf("%.7lf ",yy[i]);
	return 0;
}