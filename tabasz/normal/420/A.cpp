#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define D double

char C[100003], cc[]={'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};


int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%s", C);
	int n=0;
	while((int)C[n]!=0) n++;
	for(int i=0; i<n; i++)
	{
		if(C[i]!=C[n-i-1])
		{
			printf("NO\n");
			return 0;
		}
	}
	for(int i=0; i<n; i++)
	{
		bool b=0;
		for(int j=0; j<11; j++) if(C[i]==cc[j]) b=1;
		if(!b)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
	return 0;
}