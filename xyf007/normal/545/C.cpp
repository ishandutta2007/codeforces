#include<bits/stdc++.h>
using namespace std;
int n;
struct tree
{
	int pos,height;
}a[100001];
int main()
{
	scanf("%d",&n);
	if(n==1)
	  {
	  	printf("1");
	  	return 0;
	  }
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&a[i].pos,&a[i].height);
	int sum=2,last=a[1].pos;
	for(int i=2;i<n;i++)
	  {
	  	if(a[i].pos-a[i].height>last)
	  	  {
	  	  	sum++;
	  	  	last=a[i].pos;
	  	  	continue;
		  }
		if(a[i].pos+a[i].height<a[i+1].pos)
		  {
	  	  	sum++;
	  	  	last=a[i].pos+a[i].height;
	  	  	continue;
		  }
		last=a[i].pos;
	  }
	printf("%d",sum);
	return 0;
}