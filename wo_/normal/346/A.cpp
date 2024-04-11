#include<cstdio>
#include<algorithm>

using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	if(a<b) return gcd(b,a);
	return gcd(b,a%b);
}

int a[100];
int D;
int N;
int M;

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	D=a[0];
	for(int i=0;i<N;i++)
	{
		if(i>0) D=gcd(D,a[i]);
		M=max(M,a[i]);
	}
	int all=M/D;
	all-=N;
	if(all%2==0) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}