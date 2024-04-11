#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 30000
#define max_k 200
using namespace std;
int f[max_n+1][max_k+1][4];
int main(){
    int n,m;
	scanf("%d%d",&n,&m),memset(f[0][1],128,sizeof(f[0])-sizeof(f[0][0])),memset(f[0][0],0,sizeof(f[0][0]));
	for(int i=0,a,a2; ++i<=n; memset(f[i][0],0,sizeof(f[i][0]))){
		scanf("%d",&a);
		#define j 1
		f[i][j][1]=max(f[i-1][j][1],f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][3])-a),f[i][j][3]=max(f[i-1][j][3],f[i][j][2]=max(f[i-1][j][2],f[i-1][j-1][1])+a);
		#undef j
		a2=a<<1;
		for(int j=1; ++j<m; f[i][j][1]=max(f[i-1][j-1][1],max(f[i-1][j][1],f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][3])-a2)),f[i][j][3]=max(f[i-1][j-1][3],max(f[i-1][j][3],f[i][j][2]=max(f[i-1][j][2],f[i-1][j-1][1])+a2)));
		#define j m
		f[i][j][1]=max(f[i-1][j][1],f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][3])-a),f[i][j][3]=max(f[i-1][j][3],f[i][j][2]=max(f[i-1][j][2],f[i-1][j-1][1])+a);
		#undef j
	}
	printf("%d\n",max(f[n][m][1],f[n][m][3]));
	return 0;
}