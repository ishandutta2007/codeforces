#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[110][110];
int x[110][110],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	int ans=0;
	for (int i=n;i;i--)
		for (int j=m;j;j--){
			int k1=0;
			if (ch[i][j]=='B') k1=1; else k1=-1;
			if (x[i][j]!=k1){
				k1=k1-x[i][j]; ans++;
				for (int k2=1;k2<=i;k2++)
					for (int k3=1;k3<=j;k3++) x[k2][k3]+=k1;
			}
		}
	printf("%d\n",ans);
	return 0;
}