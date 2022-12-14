#include <cstdio>
using namespace std;
double f[110],p[110];
double cal(int x){
	return f[x]+1.0*(1-f[x])*p[x];
}
int main(){
	int n;
	double ans,lst,g;
	scanf("%d",&n),lst=1;
	for(int i=0,x; ++i<=n; f[i]=p[i]=0.01*x,lst*=p[i])
		scanf("%d",&x);
	ans=n*lst;
	for(int i=n,x=1; ++i<=300000; x=1){
		for(int j=0; ++j<=n; cal(j)/f[j]>cal(x)/f[x]&&(x=j));
		g=lst*cal(x)/f[x];
		f[x]=cal(x),ans+=i*(g-lst),lst=g;
	}
    printf("%.10lf\n", ans);
    return 0;
}