#include <bits/stdc++.h>
using namespace std;
struct qwq
{
	int a,b,c,d,e,id;
}a[50005];
inline bool cmp(qwq x,qwq y)
{
	return (x.a<y.a)+(x.b<y.b)+(x.c<y.c)+(x.d<y.d)+(x.e<y.e)>=3;
}
int ans[50005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int mx=0;
		a[0]={123456789,123456789,123456789,123456789,123456789};
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d >> a[i].e;
			a[i].id=i;
			if(cmp(a[i],a[mx])) mx=i;
		}
		int flag=1;
		for(int i=1;i<=n;i++)
			if(cmp(a[i],a[mx])) flag=0;
		if(flag)
		{
			cout << mx << "\n";
		 } else cout << "-1\n";
	}
	return 0;
}