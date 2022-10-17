#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=105;
int T,n,a,b;
int f[maxn][maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d%d%d",&n,&a,&b),cin>>s,s=" "+s;
		ans=a*n;
		if(b>=0)
			printf("%d\n",ans+n*b);
		else{
			for(int i=1;i<=n;i++)
				f[i][i]=1;
			for(int len=2;len<=n;len++)
				for(int i=1;i+len-1<=n;i++){
					int j=i+len-1;
					f[i][j]=min(f[i+1][j],f[i][j-1])+1;
					for(int k=i;k<=j;k++)
						if(s[i]==s[k])
							f[i][j]=min(f[i][j],f[i+1][k-1]+f[k][j]);
				}
			printf("%d\n",ans+f[1][n]*b);
		}
	}
	return 0;
}