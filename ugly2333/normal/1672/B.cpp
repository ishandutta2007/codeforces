//CF1672A
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
const int N = 222222;
int n;
char c[N];
int main()
{
	int T,i,f,x;
	scanf("%d",&T);
	while(T--){
		scanf("%s",c);
		n=strlen(c);
		f=c[0]=='A'&&c[n-1]=='B';
		x=0;
		for(i=0;i<n;i++){
			if(c[i]=='A')
				x++;
			else
				x--;
			if(x<0)
				f=0;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}