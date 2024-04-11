#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return (long long)x*f;
}
string x,y;
bool check;
int main()
{
	cin>>x;
	cin>>y;
	check=true;
	for (int i=0;i<x.length();i++) if (x[i]<y[i]) check=false;
	if (!(check)) cout << -1 << endl; else cout << y << endl;
	return 0;
}