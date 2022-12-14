#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n,k,l,c,d,p,nl,np;
	scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
	printf("%d\n",min(p/np,min(k*l/nl,c*d))/n);
	return 0;
}