#include<cstdio>

using namespace std;

int x,y,z;
int x1,y1,z1;
int a[6];

int main()
{
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&x1,&y1,&z1);
	for(int i=0;i<6;i++) scanf("%d",a+i);
	int res=0;
	if(x<0) res+=a[4];
	if(y<0) res+=a[0];
	if(z<0) res+=a[2];
	if(x>x1) res+=a[5];
	if(y>y1) res+=a[1];
	if(z>z1) res+=a[3];
	printf("%d",res);
	return 0;
}