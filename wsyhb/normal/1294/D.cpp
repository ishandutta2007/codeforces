#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
bool M[N];
int a[N];
int main()
{
	int q,x,ans=0;
	scanf("%d%d",&q,&x);
	for(int i=0;i<x;i++) a[i]=i;
	for(int i=1;i<=q;i++)
	{
		int y;
		scanf("%d",&y);
		y%=x;
		M[a[y]]=true;
		if(a[y]+x<=q) a[y]+=x;
		while(M[ans]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}