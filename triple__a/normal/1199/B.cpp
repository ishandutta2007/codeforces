#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long u,v;
	scanf("%lld%lld",&u,&v);
	double ans=(double)(v*v-u*u)/2/u;
	printf("%.10lf",ans);
	return 0;
}