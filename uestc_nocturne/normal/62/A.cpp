#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int AB(int x)
{if(x<0)return -x;return x;}
int l1,l2,r1,r2,flag;
int main()
{
	scanf("%d%d",&l1,&r1);
	scanf("%d%d",&l2,&r2);
	flag=0;
	if(l1>=r2&&l1-r2<=1)flag=1;
	if(l2>=r1&&l2<=2*(r1+1))flag=1;
	if(r1>=l2&&r1-l2<=1)flag=1;
	if(r2>=l1&&r2<=2*(l1+1))flag=1;
	if(flag==1)puts("YES");
	else puts("NO");
}