#include <bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int a[N][N],mx[N];
int main(){
	int n,m;scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++)a[i][j]=(int)(s[j]-'0'),mx[j]=max(mx[j],a[i][j]);
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		bool ok=false;
		for(int j=0;j<m;j++)if(a[i][j]==mx[j])ok=true;
		cnt+=ok;
	}
	printf("%i",cnt);
	return 0;
}