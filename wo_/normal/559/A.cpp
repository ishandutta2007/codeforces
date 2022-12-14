#include<cstdio>

using namespace std;

int a,b,c,d,e,f;

int main(){
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int ans=(a+e+f)*(a+e+f)-a*a-c*c-e*e;
	printf("%d\n",ans);
	return 0;
}