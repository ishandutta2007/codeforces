#include<iostream>
using namespace std;
int n,m,k,x,y,a[1020][1020],r[1020],c[1020];
char o;
#define fo(i,n) for(int i=1;i<=n;i++)
int main()
{
	cin>>n>>m>>k;
	fo(i,n)
		fo(j,m)
			cin>>a[i][j];
	fo(i,n)
		r[i]=i;
	fo(i,m)
		c[i]=i;
	fo(i,k)
	{
		cin>>o>>x>>y;
		if(o=='r')
			swap(r[x],r[y]);
		else if(o=='c')
			swap(c[x],c[y]);
		else
			cout<<a[r[x]][c[y]]<<endl;
	}
}