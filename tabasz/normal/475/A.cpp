#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back



int main()
{
	int n;
	scanf("%d", &n);
	printf("+------------------------+\n");
	bool bo=0;
	if(n>=3)
	{
		bo=1;
		n--;
	}
	int a=n/3, b=n/3, c=n/3;
	if(n%3>0) a++;
	if(n%3>1) b++;
	printf("|");
	for(int i=0; i<a; i++) printf("O.");
	for(int i=a; i<11; i++) printf("#.");
	printf("|D|)\n|");
	for(int i=0; i<b; i++) printf("O.");
	for(int i=b; i<11; i++) printf("#.");
	printf("|.|\n");
	if(bo) printf("|O.......................|\n|");
	else printf("|#.......................|\n|");
	for(int i=0; i<c; i++) printf("O.");
	for(int i=c; i<11; i++) printf("#.");
	printf("|.|)\n");
	printf("+------------------------+\n");
	return 0;
}