#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
char s[2][N];
int f[2][N];
int main(){
	scanf("%d",&n);
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	f[1][1]=s[1][1]=='1'?1:-1000000;
	f[1][0]=-1000000;
	for(int i=2;i<=n;i++){
		f[0][i]=f[0][i-1]+(s[0][i]=='1'),f[1][i]=f[1][i-1]+(s[1][i]=='1');
		if(s[0][i]=='1')f[0][i]=max(f[0][i],f[1][i-2]+1+(s[1][i-1]=='1'));
		if(s[1][i]=='1')f[1][i]=max(f[1][i],f[0][i-2]+1+(s[0][i-1]=='1'));
		if(s[0][i]=='1'&&s[1][i]=='1'){
			f[0][i]=max(f[0][i],f[1][i-2]+2+(s[1][i-1]=='1'));
			f[1][i]=max(f[1][i],f[0][i-2]+2+(s[0][i-1]=='1'));
		}
	}
	cout<<max(f[0][n],f[1][n])<<endl;
	return 0;
}