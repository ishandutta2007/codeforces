#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

char s[20];
int f[11][7][7];
void solve(){
	scanf("%s",s+1);
	memset(f,0,sizeof(f));
	f[0][0][0]=1;
	for (int i=1;i<=10;i++){
		for (int j=0;j<=5;j++)
			for (int k=0;k<=5;k++){
				if (s[i]!='0') f[i][j+(i&1)][k+1-(i&1)]|=f[i-1][j][k];
				if (s[i]!='1') f[i][j][k]|=f[i-1][j][k];
			}
		int r1=5-(i+1)/2,r2=5-i/2;
		for (int j=0;j<=5;j++)
			for (int k=0;k<=5;k++)
				if (f[i][j][k])
					if (j+r1<k||k+r2<j){
						printf("%d\n",i);
						return;
					}
	}
	printf("%d\n",10);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}