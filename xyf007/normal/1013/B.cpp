#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001],c[100001],x;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	b[a[i]]++;
	  	c[a[i]&x]++;
	  }
	bool f=1;
	for(int i=0;i<=100000;i++)
	  if(b[i]>=2)
	    {
	      f=0;
	      printf("0");
	      break;
	    }
	for(int i=0;i<=n&&f;i++)
	  {
	  	b[a[i]]--;
	  	if(b[a[i]&x]==1)
	      {
	        f=0;
	        printf("1");
	        break;
		  }
		b[a[i]]++;	
	  }
	for(int i=0;i<=100000&&f;i++)
	  if(c[i]>=2)
	    {
	      f=0;
	      printf("2");
	      break;
		}
	if(f)
	  printf("-1");
	return 0;
}