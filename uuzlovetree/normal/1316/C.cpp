#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,m,p;
int a[maxn],b[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<n;++i)scanf("%d",&a[i]),a[i]%=p;
	for(int i=0;i<m;++i)scanf("%d",&b[i]),b[i]%=p;
	int i=0,j=0;
	while(1)
	{
		if(a[i]!=0&&b[j]!=0)
		{
			printf("%d\n",i+j);
			break;
		}
		if(!a[i])i++;
		if(!b[j])j++;
	}
}