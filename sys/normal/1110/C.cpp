#include <bits/stdc++.h>
using namespace std;
int q,n,maxi[30];
void init(int x,int pos)
{
	maxi[pos]=1;
	int mai=sqrt(x);
	for(int i=2;i<=mai;i++)
		if(x%i==0)
		{
			maxi[pos]=x/i;
			return ;
		}
}
int main()
{
	scanf("%d",&q);
	for(int i=0;i<=25;i++)
		init((1<<i)-1,i);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&n);
		if(log2(n+1)==(int)log2(n+1)) printf("%d\n",maxi[(int)log2(n+1)]);
		else
			printf("%d\n",(int)pow(2,1+(int)log2(n))-1);
	}
	return 0;
}