//CF1616B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1111111;
int n;
char s[N];
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		if(n==1||s[1]<=s[2])
			x=1;
		else{
			for(i=1;i<n;i++)
				if(s[i]<s[i+1])
					break;
			if(i>=n)
				x=n;
			else
				x=i;
		}
		for(i=1;i<=x;i++)
			printf("%c",s[i]);
		for(i=x;i>=1;i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}