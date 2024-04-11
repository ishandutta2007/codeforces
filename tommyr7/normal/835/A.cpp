#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int s,v1,v2,t1,t2;
int main()
{
	s=read(),v1=read(),v2=read(),t1=read(),t2=read();
	int cnt1=2*t1+s*v1;
	int cnt2=2*t2+s*v2;
	if (cnt1<cnt2) printf("First\n");
	else if (cnt1>cnt2) printf("Second\n");
	else printf("Friendship\n");
	return 0;
}