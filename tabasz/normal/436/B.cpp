#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define MP make_pair
#define PB push_back
#define S second
#define F first
#define LL long long
#define D double

int T[2002];

int main()
{
	int n, m, k;
	char c;
	scanf("%d%d%d%c", &n, &m, &k, &c);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%c", &c);
			if(c=='U') if(!(i%2)) T[j]++;
			if(c=='R') if(j+i<m) T[j+i]++;
			if(c=='L') if(j-i>=0) T[j-i]++;
		}
		scanf("%c", &c);
	}
	for(int j=0; j<m; j++) printf("%d ", T[j]);
	printf("\n");
	return 0;
}