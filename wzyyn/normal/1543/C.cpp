#include<bits/stdc++.h>
#define ll long long
using namespace std;

double v;
double G(double a,double b){
	double ans=1;
	if (b>v+1e-8) ans+=b*G(a+v,b-v);
	else ans+=b;
	return ans;
}
double F(double a,double b,double c){
	double ans=1;
	if (a>v+1e-8) ans+=a*F(a-v,b+v/2,c+v/2);
	else ans+=a*G(b+a/2,c+a/2);
	if (c>v+1e-8) ans+=c*F(a+v/2,b+v/2,c-v);
	else ans+=c*G(b+c/2,a+c/2);
	return ans;
}
void solve(){
	double c,m,p;
	scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
	printf("%.15lf\n",F(c,p,m));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}