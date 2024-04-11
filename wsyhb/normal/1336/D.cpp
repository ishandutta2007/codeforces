//
#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int a[max_n],c1[max_n],c2[max_n];
int main()
{
	int n;
	scanf("%d%d%d",&n,c1,c2);
	for(int i=1;i<=n-3;++i)
	{
		cout<<"+ "<<n-i<<endl;
		scanf("%d%d",c1+i,c2+i);
	}
	cout<<"+ 1"<<endl;
	scanf("%d%d",c1+(n-2),c2+(n-2));
	cout<<"+ 2"<<endl;
	scanf("%d%d",c1+(n-1),c2+(n-1));
	cout<<"+ 1"<<endl;
	scanf("%d%d",c1+n,c2+n);
	for(int i=0;i<=n;++i)
	{
		if((i+1)*i/2==c1[n]-c1[n-1])
		{
			a[1]=i;
			break;
		}
	}
	int p=c2[n-2]-c2[n-3],q=c2[n]-c2[n-1];
	a[3]=q-p-1,a[2]=p/(a[3]+1);
	a[4]=((c2[n-1]-c2[n-2])-(a[1]+1)*(a[3]+1))/(a[3]+1)-(n>4);
	for(int x=3;x<=n-3;++x)
		a[x+2]=((c2[n-x]-c2[n-x-1])-a[x-2]*a[x-1]-a[x-1]*(a[x+1]+1))/(a[x+1]+1)-1;
	if(n>4)
		a[n]=((c2[2]-c2[1])-a[n-4]*a[n-3]-a[n-3]*(a[n-1]+1))/(a[n-1]+1);
	cout<<"!";
	for(int i=1;i<=n;++i)
		cout<<' '<<a[i];
	cout<<endl;
	return 0;
}
/*
4
1 0 1 2
*/