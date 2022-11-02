#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define int LL

int n, P[22];
int R[1000005];
char C[5];

int getnum(int x)
{
	int i=1, r=0, tmp=0;
	while(x/i>0)
	{
		//printf("lol %d %d %d\n", x, i, P[tmp]);
		if((x/i)%2)
			r+=P[tmp];
		//printf("    %d %d\n", x, r);
		tmp++;
		i*=10;
	}
	return r;
}

main()
{
	P[0]=1;
	for(int i=1; i<22; i++)
		P[i]=P[i-1]*2;
	scanf("%lld", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%s%lld", C, &a);
		//printf("%d: %d\n", a, getnum(a));
		if(C[0]=='+')
			R[getnum(a)]++;
		if(C[0]=='-')
			R[getnum(a)]--;
		if(C[0]=='?')
			printf("%lld\n", R[getnum(a)]);
	}
	return 0;
}