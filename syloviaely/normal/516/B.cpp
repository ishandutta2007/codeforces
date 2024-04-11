#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
char ch[2100][2100];
int d[2100][2100],n,m,gox[4]={1,0,-1,0},goy[4]={0,1,0,-1},s[4000010][2],len,pd[2100][2100],tot;
void print(int k1,int k2,int k3,int k4){
	tot-=2;
	if (k1==k3){
		ch[k1][min(k2,k4)]='<'; ch[k1][max(k2,k4)]='>';
	} else {
		ch[min(k1,k3)][k2]='^'; ch[max(k1,k3)][k2]='v';
	}
	pd[k1][k2]=1; pd[k3][k4]=1;
	for (int i=0;i<4;i++){
		int a=k3+gox[i],b=k4+goy[i];
		if (pd[a][b]==0&&ch[a][b]=='.'){
			d[a][b]--; if (d[a][b]==1){len++; s[len][0]=a; s[len][1]=b;}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	tot=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			if (ch[i][j]=='.'){
				for (int k=0;k<4;k++){
					int k1=i+gox[k],k2=j+goy[k];
					if (ch[k1][k2]=='.') d[i][j]++;
				}
				if (d[i][j]==1){
					len++; s[len][0]=i; s[len][1]=j;
				}
				tot++;
			}
	int now=0;
	while (now<len){
		now++; int k1=s[now][0],k2=s[now][1];
		if (pd[k1][k2]) continue;
		for (int i=0;i<4;i++){
			int a=k1+gox[i],b=k2+goy[i];
			if (pd[a][b]==0&&ch[a][b]=='.') print(k1,k2,a,b);
		}
	}
	if (tot){
		printf("Not unique\n"); return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) putchar(ch[i][j]); putchar('\n');
	}
	return 0;
}