#include<cstdio>

using namespace std;

int a[2],b[2];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a1,b1,c1;
		scanf("%d%d%d",&a1,&b1,&c1);
		if(a1==1) a[0]+=b1,a[1]+=c1;
		else b[0]+=b1,b[1]+=c1;
	}
	if(a[0]>=a[1]) printf("LIVE\n");
	else printf("DEAD\n");
	if(b[0]>=b[1]) printf("LIVE\n");
	else printf("DEAD\n");
	return 0;
}