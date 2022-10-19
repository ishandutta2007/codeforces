#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,f[N],b;
void no(){puts("NO");exit(0);}
int ok(int x){return x==(x&(-x));}
int main()
{
	scanf("%d%d",&n,&k);
	if(n%2==0)	no();
	if(k>max((n-3)/2,0)) no();
	if(n==9&&k==2) no();
	if(ok(n+1)&&k==1) no();
	if(!ok(n+1)&&k==0) no();
	puts("Yes");
	b=2*max(0,k-1);
	for(int i=1;i<b;i+=2)
		f[i+1]=i,f[i]=max(0,i-2);
	for(int i=1;i<=n-b;i++)
	{
		if(i==1) f[i+b]=max(0,b-1);
		else f[i+b]=(i>>1)+b;
	}
	if(ok(n-b+1)&&k)
		f[n-1]=f[n]=2;
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	return 0;
}