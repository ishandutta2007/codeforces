#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,h;
double ans;
int main()
{
	n=read(),h=read();
	for (int i=1;i<n;i++)
	{
		ans=(double)1.0*h*(double)((double)sqrt((double)1.0*i/n));
		printf("%.12lf ",ans);
	}
	cout << endl;
	return 0;
}