#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,a[1001][1001],ln,ls[100001]; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		bool ok=1;
		for(int j=1;j<=n;j++) if(a[i][j]==3||a[i][j]==1) ok=0;
		if(ok) ls[++ln]=i;
	}
	cout<<ln<<"\n";
	for(int i=1;i<=ln;i++) cout<<ls[i]<<" ";
}