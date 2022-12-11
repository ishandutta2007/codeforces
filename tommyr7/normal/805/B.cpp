#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		if (i%4==1||i%4==2) printf("a"); else printf("b");
	}
	cout << endl;
	return 0;
}