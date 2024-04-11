#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,k,r,a[N],x,y,od[N];
int main()
{
	scanf("%d%d",&n,&k);
	if(k%2==0&&n%2==1)
	{
		puts("-1");
		return 0;
	}
	r=k;
	while(r<n||((r-n)&1)||(1+2*(((r-n)/2+n-1)/n))>r/k)
		r+=k;
	for(int i=0;i<n;i++)
		a[i]=1;
	for(int i=0;i<(r-n)/2;i++)
		a[i%n]+=2;
	for(int i=0;i<r/k;i++)
	{
		for(int j=0;j<n;j++)
			od[j]=j;
		sort(od,od+n,[&](int x,int y){return a[x]>a[y];});
		printf("?");
		for(int j=0;j<k;j++)
		{
			printf(" %d",od[j]+1);
			a[od[j]]--;
		}
		puts("");
		fflush(stdout);
		scanf("%d",&y);
		x^=y;
	}
	printf("! %d\n",x);
	return 0;
}