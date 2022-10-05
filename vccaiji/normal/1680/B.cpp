#include<bits/stdc++.h>
using namespace std;
char s[11][11];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		int ii=0,jj=0,r=1;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='R'){
			if(!ii){
				ii=i;jj=j;
				continue;
			}
			if(ii>i||jj>j)r=0;
		}
		printf(r ? "YES\n" : "NO\n");
	}
	return 0;
}