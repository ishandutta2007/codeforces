#include<bits/stdc++.h>
using namespace std;
const int maxn=40005,mod=1000000007;
int n,m,T,ans;
int f[maxn],num[maxn];
string s;
int main(){
	f[0]=1;
	for(int i=1;i<=40000;i++){
		int j=i,len=0,flg=1;
		while(j)
			num[++len]=j%10,j/=10;
		for(int k=1;k<=len-k+1;k++)
			flg&=(num[k]==num[len-k+1]);
		if(flg)
			for(int k=i;k<=40000;k++)
				f[k]=(f[k]+f[k-i])%mod;
	}
	scanf("%d",&T);
	while(T--)
		scanf("%d",&n),printf("%d\n",f[n]);
	return 0;
}