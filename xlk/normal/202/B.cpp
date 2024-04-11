#include<stdio.h>
#include<iostream>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
int n,m,k,z,v,p[9];
string s[9],c[30];
void dfs(int x,int y)
{
	if(x==n)
	{
		int u=0;
		fr(j,n)
			fr(i,j)
				if(p[i]>p[j])
					u++;
		if(z<(n-1)*n/2-u+1)
			z=(n-1)*n/2-u+1,v=y;
		return;
	}
	fr(i,k)
		if(s[x]==c[i])
		{
			p[x]=i;
			dfs(x+1,y);
		}
}
int main()
{
	cin>>n;
	fr(i,n)
		cin>>s[i];
	cin>>m;
	fr(i,m)
	{
		cin>>k;
		fr(j,k)
			cin>>c[j];
		dfs(0,i+1);
	}
	if(v)
		cout << v << endl << "[:" << string(z,'|') << ":]" << endl;
	else
		puts("Brand new problem!");
}