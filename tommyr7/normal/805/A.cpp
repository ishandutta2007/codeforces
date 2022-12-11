#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int l,r;
int main()
{
	l=read(),r=read();
	int ans2=(r/2)-(l/2);
	int ans3=(r/3)-(l/3);
	if (l==r) printf("%d\n",l); else if (ans2>=ans3) printf("%d\n",2); else printf("%d\n",3);
	return 0;
}