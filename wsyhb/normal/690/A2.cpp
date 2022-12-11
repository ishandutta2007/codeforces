#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	if(N&1)
		printf("%d\n",N>>1);
	else
	{
		int M=2;
		while((M<<1)<=N)
			M<<=1;
		printf("%d\n",(N-M)>>1);
	}
	return 0;
}