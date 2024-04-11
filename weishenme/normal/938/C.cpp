#include<bits/stdc++.h>
using namespace std;
int T,x;
int ef(int x,int y)
{
	int l=1,r=x;
	while (l<=r)
	 {
	 	int mid=(l+r)/2;
	 	if (x/mid==y)return mid;
	 	if (x/mid<y)r=mid-1;
	 	else l=mid+1;
	 }
	return -1; 
}
int main()
{
	scanf("%d",&T);
	while (T--)
	 {
	 	scanf("%d",&x);
	 	if (!x)
	 	 {
	 	 	puts("1 1");
	 	 	continue;
	 	 }
	 	int flag=0; 
	 	for (int i=1;i*i<=2e9;i++)
		 {
		 	int k=i*i-x;
		 	if (k<=0)continue;
		 	if ((int)sqrt(k)*(int)sqrt(k)!=k)continue;
		 	int l=ef(i,(int)sqrt(k));
		 	if (l!=-1)
		 	 {
		 	 	flag=1;
		 	 	printf("%d %d\n",i,l);
		 	 	break;
		 	 }
		 } 
		if (!flag)puts("-1"); 
	 }
}