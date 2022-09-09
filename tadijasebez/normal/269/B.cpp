#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=5050;
int id[N],b[N],S[N],c;
long double x[N];
bool comp(int i, int j){ return x[i]<x[j];}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&b[i]),cin >> x[i],id[i]=i;
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n;i++) j=upper_bound(S+1,S+1+c,b[id[i]])-S,S[j]=b[id[i]],c=(j>c?j:c);
	printf("%i\n",n-c);
	return 0;
}