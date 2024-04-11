#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 105
using namespace std;
int n,f[MAXN][2];
char s[MAXN];
int main(){
	memset(f,63,sizeof(f));
	f[0][0]=f[0][1]=1;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<n;i++){
		f[i][0]=f[i-1][0]+1;
		if (i&1){
			if (!strncmp(s,s+(i+1>>1),i+1>>1)) f[i][1]=f[i>>1][0]+1;
			else f[i][1]=f[i-1][1]+1;
		} else f[i][1]=f[i-1][1]+1;
	}
	printf("%d\n",min(f[n-1][0],f[n-1][1]));
	return 0;
}