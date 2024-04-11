#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=505;
int n,m,c,d,T,ans;
int a[maxn][maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d%d%d",&n,&m,&c,&d);
		int flg=0;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++)
				a[i][j]=s[j-1]=='B',flg|=a[i][j];
		}
		if(flg==0){
			puts("-1");
			continue;
		}
		int f1=1,f2=1,f3=0,f4=0;
		for(int i=1;i<=m;i++)
			f1&=a[c][i],f3|=a[c][i];
		for(int i=1;i<=n;i++)
			f2&=a[i][d],f4|=a[i][d];
		if(a[c][d])
			puts("0");
		else if(f3||f4)
			puts("1");
		else puts("2");
	}
	return 0;
}