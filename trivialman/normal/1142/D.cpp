#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i) 
 
int f[11],g[11],n;
long long ans;
char s[100010];
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	F(i,1,n) s[i] -= '0';
	F(i,1,n){
		F(j,s[i]+1,10) f[(j*(j-1)/2+s[i]+10)%11] += g[j];
		if(s[i]) ++f[s[i]];
		F(j,0,10) ans += f[j];
		memcpy(g,f,sizeof g);
		memset(f,0,sizeof f);
	}
	printf("%I64d\n",ans);
}