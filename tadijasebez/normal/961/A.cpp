
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
int min(int a, int b){ return a>b?b:a;}
const int N=100000;
int a[N];
int main()
{
	int n,m,i,x;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i",&x),a[x]++;
	int sol=10000000;
	for(i=1;i<=n;i++) sol=min(sol,a[i]);
	printf("%i\n",sol);
	return 0;
}