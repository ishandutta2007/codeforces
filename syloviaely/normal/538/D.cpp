#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int pd[60][60],bo[110][110],n;
char ch[60];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for (int j=1;j<=n;j++) if (ch[j]=='o') pd[i][j]=2; else if (ch[j]=='x') pd[i][j]=1; else pd[i][j]=0;
	}
	for (int i=1;i<=n*2-1;i++)
		for (int j=1;j<=n*2-1;j++){
			int flag=0;
			for (int k1=1;k1<=n;k1++)
				for (int k2=1;k2<=n;k2++){
					int a=k1+i-n,b=k2+j-n;
					if (a>0&&a<=n&&b>0&&b<=n&&pd[k1][k2]==2)
						if (pd[a][b]==0) {flag=1; break;}
				}
			if (flag==0){
				bo[i][j]=1;	
				for (int k1=1;k1<=n;k1++)
					for (int k2=1;k2<=n;k2++){
						int a=k1+i-n,b=k2+j-n;
						if (a>0&&a<=n&&b>0&&b<=n&&pd[k1][k2]==2)
							if (pd[a][b]==1) pd[a][b]=-1;
					}
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (pd[i][j]==1){
			printf("NO\n"); return 0;
		}
	printf("YES\n");
	for (int i=1;i<=n*2-1;i++){
		for (int j=1;j<=n*2-1;j++)
			if (i==n&&j==n) putchar('o'); else if (bo[i][j]) putchar('x'); else putchar('.');
		cout<<endl;
	}
	return 0;
}