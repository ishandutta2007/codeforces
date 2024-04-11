#include<bits/stdc++.h>
#define P 998244353
#define N 200005

inline int fmo(int x){
	return x+((x>>31)&P);
}

int n;
char s[N];

int f[N][2][2][2];
inline int dfs(int o,int x,int y,int z){
	if(o>n)
		return 1;
	if(~f[o][x][y][z])
		return f[o][x][y][z];
	int res=0;
	for(int i=0;i<2;i++) if(!(x&&i==1&&s[o]=='0'))
		for(int j=0;j<2;j++) if(!(y&&j==1&&s[o]=='0'))
			for(int k=0;k<2;k++) if(!(z&&k==1&&s[o]=='0')) if(!(i==j&&k!=i))
				res=fmo(res+dfs(o+1,x&&(i==s[o]-'0'),y&&(j==s[o]-'0'),z&&(k==s[o]-'0'))-P);
	return f[o][x][y][z]=res;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int t=0;
	for(int i=1;i<=n;i++)
		t=fmo(t+t-P),t=fmo(t+s[i]-'0'-P);
	t=fmo(t+1-P);
	memset(f,-1,sizeof(f));
	int res=dfs(1,1,1,1);
	printf("%d\n",fmo(fmo(fmo(1ll*t*t%P*t%P+3ll*t%P*t%P-P)-t)-3ll*res%P));
}