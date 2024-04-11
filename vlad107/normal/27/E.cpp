#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

#define INF 1000000000000000000LL
#define MAXN 1011

long long f[MAXN][MAXN];
int n;
bool prime[MAXN];
std::vector<int>pr;

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	memset(prime,true,sizeof(prime));
	for (int i=2;i<MAXN;i++)
		if (prime[i]){
			pr.push_back(i);
			for (int j=i+i;j<MAXN;j+=i)
				prime[j]=false;
		}
	int m=pr.size();
	for (int i=0;i<=m;i++)
		for (int j=0;j<=n;j++)
			f[i][j]=INF;
	f[0][1]=1;
	for (int i=0;i<m;i++)
		for (int j=0;j<=n;j++){
			long long x=f[i][j];
			if (x==INF)continue;
			for (int k=0;k<=n;k++){
				if (j*(k+1)>n)break;
				if (x<f[i+1][j*(k+1)])f[i+1][j*(k+1)]=x;
				if (INF/pr[i]<x)break;
				x*=pr[i];
			}	
		}
	printf("%I64d",f[m][n]);
}