#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[5][5];
int main()
{
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			a[i][j]=read();
	bool check=true;
	for (int i=0;i<4;i++)
		if (a[i][3])
		{
			if (a[i][1]||a[i][0]||a[i][2]||a[(i+2)%4][1]) check=false;
			if (a[(i+1)%4][0]||a[(i+3)%4][2]) check=false;
		}
	if (!check) cout << "YES" << endl; else cout << "NO" << endl;
	return 0;
}