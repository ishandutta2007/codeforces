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
#define X first
#define Y second
typedef pair<int,int>ii;
ii a[600020];
int n;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	fr(i,n*2)
		scanf("%d",&a[i].X),a[i].Y=i;
	sort(a,a+2*n);
	for(int i=0;i<n*2;i+=2)
		if(a[i].X!=a[i+1].X)
			return puts("-1"),0;
	for(int i=0;i<n*2;i+=2)
		printf("%d %d\n",a[i].Y+1,a[i+1].Y+1);
}