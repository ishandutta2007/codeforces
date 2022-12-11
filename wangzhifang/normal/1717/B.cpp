#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_n=500;
char a[max_n+1][max_n+1];
void test(){
	int n,k,r,c;
	scanf("%d%d%d%d",&n,&k,&r,&c);
	r%=k,c%=k;
	for(int i=0; i<k; ++i){
		for(int j=0; j<k; ++j)
			a[i][j]='.';
		if(i!=r&&i!=c)
			a[i][i]='X';
	}
	a[r][c]=a[c][r]='X';
	for(int i=1; i<=n; ++i,putchar('\n'))
		for(int j=1; j<=n; ++j)
			putchar(a[i%k][j%k]);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}