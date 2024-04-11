#include<cstdio>

using namespace std;

int get(int a,int b)
{
	if(a<b) return get(b,a);
	//a>=b
	if(a%b==0)
	{
		return a/b;
	}
	int c=a/b;
	return get(b,a%b)+c;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",get(a,b));
	}
	return 0;
}