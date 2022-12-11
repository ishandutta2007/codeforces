#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
    int n=read();
	if (n>=3){
	int ans=2;
	printf("%d\n",ans);
	for (int i=2;i<=n+1;i++)
	{
		bool flag=true;
		for (int j=2;j*j<=i;j++)
			if (i%j==0) flag=false;
		if (flag) printf("%d ",1); else printf("%d ",2);
	}
} else
{
	printf("%d\n",1);
	for (int i=1;i<=n;i++)
		printf("%d ",1);
}
	printf("\n");
    return 0;
}