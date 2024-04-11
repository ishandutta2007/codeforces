#include <stdio.h>
int n,m,k;
char a[500][500];
int main(){
	scanf("%d%d%d\n",&n,&m,&k);
	for (int i=0;i<n;i++)gets(a[i]);
	for (int r=1;r<n;r++)
		for (int i=r;i<n-r;i++)
			for (int j=r;j<m-r;j++)
				if (a[i][j]=='*'&&a[i+r][j]=='*'&&a[i][j+r]=='*'&&a[i-r][j]=='*'&&a[i][j-r]=='*'){
					k--;
					if (!k){
						printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i+1,j+1,i-r+1,j+1,i+r+1,j+1,i+1,j-r+1,i+1,j+r+1);
						return 0;
					}
				}
	printf("-1\n");
}