#include<bits/stdc++.h>
using namespace std;
int T,n,m,res;
char s[110][110];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),res=0;
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<m;i++)res+=(s[n][i]=='D');
		for(int i=1;i<n;i++)res+=(s[i][m]=='R');
		printf("%d\n",res); 
	}
	return 0;
}