//CF1383A
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
const int K = 22;
int n,k=20,e[K][K];
char a[N],b[N];
int main()
{
	int T,i,j,s,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,a,b);
		for(i=0;i<k;i=i+1)
			for(j=0;j<k;j=j+1)
				e[i][j]=0;
		for(i=0;i<n;i=i+1)
			e[a[i]-'a'][b[i]-'a']=1;
		s=0;
		for(i=0;i<k;i=i+1)
			for(j=0;j<k;j=j+1)
				if(e[i][j]&&i>j)
					s=1;
		if(s){
			printf("-1\n");
			continue;
		}
		s=0;
		for(i=0;i<k;i=i+1){
			x=0;
			for(j=i+1;j<k;j=j+1){
				if(e[i][j]){
					x=j;
					break;
				}
			}
			if(x){
				s++;
				for(j=x+1;j<k;j=j+1)
					if(e[i][j])
						e[x][j]=1;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}