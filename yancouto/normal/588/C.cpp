#include<bits/stdc++.h>
using namespace std;
typedef int num;
typedef int node;
typedef int edge;

const int MN = 2000000;
int freq[MN], n, ans;
char str[1000]; int sn;
int main()
{
	fgets(str, sizeof str, stdin);
	n = atoi(str);
	for(int i=0;i<n;i++)
	{
		int aux;
		char c;
		while(isspace(c = getchar()));
		str[0] = c; sn = 1;
		while(isdigit(str[sn++] = getchar()));
		str[sn - 1] = 0;
		aux = atoi(str);
		freq[aux]++;
	}

	for(int i=0;i<MN-1;i++)
	{
		freq[i+1] += freq[i]/2;
		freq[i] %= 2;
		ans += !!(freq[i]);
	}

	printf("%d\n", ans);
}