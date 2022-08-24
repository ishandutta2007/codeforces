#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int n,r;
int x[1100];
double ans[11000];
int main(){
	scanf("%d%d",&n,&r);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++){
		double now=r;
		for (int j=1;j<i;j++)
			if (abs(x[i]-x[j])<=2*r){
				int dis=abs(x[i]-x[j]);
				double K=sqrt(4*r*r-dis*dis);
				now=max(now,K+ans[j]);
			}
		ans[i]=now;
	}
	for (int i=1;i<=n;i++) printf("%.11lf ",ans[i]);
	printf("\n");
}