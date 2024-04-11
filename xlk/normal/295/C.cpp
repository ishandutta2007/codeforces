#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
int mo=1000000007;
using namespace std;
struct N
{
	int a;
	bool b;
	N(int a=0,bool b=0):a(a),b(b){}
	N operator+(N A)
	{
		N re;
		re.b=b|A.b;
		re.a=(a+A.a)%mo;
		return re;
	}
	N operator*(int w)
	{
		N re;
		re=*this;
		re.a=(ll)re.a*w%mo;
		return re;
	}
};
N f[200][100][100];
int n,c1,c2,w,tt;
int a[1000020],b[1000020],c[1000020],d[1000020],e[1000020];
int C[1001][1001];
int ok(int a, int b, int c, int d, int w)
{
	int nc=c1-a,nd=c2-b;
	if(nc==c&&nd==d)
		return 0;
	if(nc>c||nd>d)
		return 0;
	if(((c-nc)*50+(d-nd)*100)>w)
		return 0;
	return (ll)C[a][c-nc]*C[b][d-nd]%mo;
}
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==50)
			++c1;
		else
			++c2;
	}
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	f[0][c1][c2]=N(1,1);
	for(int i=0;i<=c1;i++)
		for(int j=0;j<=c2;j++)
			for(int k=0;k<=c1;k++)
				for(int l=0;l<=c2;l++)
				{
					int x=0;
					if(x=ok(i,j,k,l,w))
					{
						++tt;
						a[tt]=i;
						b[tt]=j;
						c[tt]=k;
						d[tt]=l;
						e[tt]=x;
					}
				}
	for(int i=0;i<n*4;i++)
	{
		for(int j=1;j<=tt;j++)
			f[i+1][c[j]][d[j]]=(f[i][a[j]][b[j]]*e[j]+f[i+1][c[j]][d[j]]);
		if(i%2==0)
		{
			if(f[i+1][c1][c2].b)
			{
				cout << i+1 << endl << f[i+1][c1][c2].a << endl;
				return 0;
			}
		}
		else
		{
			if(f[i+1][0][0].b)
			{
				cout << i+1 << endl << f[i+1][0][0].a << endl;
				return 0;
			}
		}
	}
	puts("-1");
	puts("0");
}