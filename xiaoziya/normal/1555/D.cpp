#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=200005;
int n,q;
int sum[maxn][3][3],ord[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
string s;
int main(){
	scanf("%d%d",&n,&q),cin>>s;
	for(int i=1;i<=n;i++){
		for(int a=0;a<3;a++)
			for(int b=0;b<3;b++)
				sum[i][a][b]=sum[i-1][a][b];
		sum[i][i%3][s[i-1]-97]++;
	}
	for(int i=1;i<=q;i++){
		int l,r,res=n;
		scanf("%d%d",&l,&r);
		if(r-l+1<3){
			if(r-l+1==1)
				puts("0");
			else puts(s[l-1]==s[r-1]? "1":"0");
			continue;
		}
		for(int j=0;j<6;j++){
			int a=ord[j][0],b=ord[j][1],c=ord[j][2];
			int tot=sum[r][0][a]-sum[l-1][0][a]+sum[r][1][b]-sum[l-1][1][b]+sum[r][2][c]-sum[l-1][2][c];
			res=min(res,r-l+1-tot);
		}
		printf("%d\n",res);
	}
	return 0;
}