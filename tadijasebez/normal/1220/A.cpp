#include <bits/stdc++.h>
using namespace std;
const int N=100050;
char s[N];
int main()
{
	map<char,int> cnt;
	int n;
	scanf("%i %s",&n,&s);
	for(int i=0;i<n;i++) cnt[s[i]]++;
	int one=cnt['n'],zero=cnt['z'];
	while(one--) printf("1 ");
	while(zero--) printf("0 ");
	return 0;
}