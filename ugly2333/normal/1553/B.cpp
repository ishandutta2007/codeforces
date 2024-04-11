//CF1553B
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
const int N = 5555;
int n,m;
char s[N],t[N];
int main()
{
	int T,i,j,k,l,x,f;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		f=0;
		for(i=1;!f&&i<=n;i++){
			for(j=i;!f&&j<=n;j++){
				l=i;
				x=1;
				for(k=1;x&&k<=m;k++){
					if(l<=0||t[k]!=s[l]){
						x=0;
						break;
					}
					if(k<=j-i)
						l++;
					else
						l--;
				}
				if(x)
					f=1;
			}
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}