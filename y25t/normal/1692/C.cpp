#include<bits/stdc++.h>

int T;

int n=8;
char s[10][10];

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=2;i<n;i++) for(int j=2;j<n;j++){
			bool flg=s[i][j]=='#';
			for(int k=i-1;k<=i+1;k+=2) for(int l=j-1;l<=j+1;l+=2)
				flg&=s[k][l]=='#';
			if(flg)
				printf("%d %d\n",i,j);
		}
	}
}