#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int query(int x,int y)
{
	assert(x>=1&&x<=n&&y>=1&&y<=m);
	printf("SCAN %d %d\n",x,y);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
inline int check(int x,int y)
{
	assert(x>=1&&x<=n&&y>=1&&y<=m);
	printf("DIG %d %d\n",x,y);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int s1=query(1,1),s2=query(1,m);
		int t1=((s1+4)+(s2+2-2*m))/2; // r1+r2
		int t2=((s1+4)-(s2+2-2*m))/2; // c1+c2
		int t3=query(t1>>1,1)-(t2-2); // |r1-r2|
		int t4=query(1,t2>>1)-(t1-2); // |c1-c2|
		int r1=(t1+t3)>>1,r2=t1-r1;
		int c1=(t2+t4)>>1,c2=t2-c1;
		if(check(r1,c1))
			assert(check(r2,c2));
		else
		{
			assert(check(r1,c2));
			assert(check(r2,c1));
		}
	}
	return 0;
}