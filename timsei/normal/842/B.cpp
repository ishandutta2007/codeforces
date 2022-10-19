#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 600005;
const double eps = 1e-8;

double x[N] , y[N] , r[N] , R , D;
int n , ans;
int main() {
	cin>>R>>D;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) {
		cin>>x[i]>>y[i]>>r[i];
		double dis = sqrt(x[i] * x[i] + y[i] * y[i]);
		if(R - r[i] - dis >= 0) {
			if(R - D - dis + r[i] <= 0) ans ++;
		}
	}
	cout<<ans<<endl;
}