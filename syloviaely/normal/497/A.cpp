#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int dp[2000],n,m,s[2000],head=0,pd[2000];
char ch[1100][1100];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",ch[i]+1); int num=0;
	for (int i=1;i<=m;i++){
		int flag=0;
		for (int j=1;j<n;j++) if (ch[j+1][i]<ch[j][i]&&pd[j]==0){flag=1; break;}
		num+=flag;
		if (flag==0){
			for (int j=1;j<n;j++) if (ch[j][i]<ch[j+1][i]) pd[j]=1;
		}
	}
	cout<<num<<endl; return 0;
}