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

int a, b, c;
bool B[10005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &a, &b, &c);
	B[0]=1;
	for(int i=0; i<=c-a; i++)
		if(B[i])
			B[i+a]=1;
	for(int i=0; i<=c-b; i++)
		if(B[i])
			B[i+b]=1;
	if(B[c])
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}