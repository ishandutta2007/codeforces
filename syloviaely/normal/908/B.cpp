#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
char ch[110];
int pd[60][60],n,m,a[10],len,ans;
int gox[4]={1,0,-1,0},goy[4]={0,1,0,-1};
int check(int k1,int k2){
	if (k1<1||k1>n||k2<1||k2>m) return 0;
	if (pd[k1][k2]=='#') return 0;
	if (pd[k1][k2]=='E') return 1;
	return 2;
}
int check(){
	int x=0,y=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) if (pd[i][j]=='S') x=i,y=j;
	for (int i=1;i<=len;i++){
		int k=a[ch[i]-'0'+1]-1;
		x+=gox[k]; y+=goy[k];
		int num=check(x,y);
		if (num==1) return 1;
		if (num==0) return 0;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for (int j=1;j<=m;j++) pd[i][j]=ch[j];
	}
	for (int i=1;i<=4;i++) a[i]=i;
	scanf("%s",ch+1); len=strlen(ch+1);
	do{
		if (check()) ans++;
	}while (next_permutation(a+1,a+5));
	cout<<ans<<endl;
}