//CF1553D
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
const int N = 111111;
int n,m;
char s[N],t[N];
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		x=1;
		j=n;
		for(i=m;i>=1;){
			if(j<=0){
				x=0;
				break;
			}
			if(s[j]==t[i])
				j--,i--;
			else
				j-=2;
		}
		if(x)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}