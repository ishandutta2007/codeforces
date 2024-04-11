#include<bits/stdc++.h>
using namespace std;
int f[255][255][255],nxt[100005][26],n,q,len[5],lst[60];
char a[3][1005],s[100005];
inline void dp(int i,int j,int k) 
{
	if(!(i|j|k)) 
		return;
	f[i][j][k]=n+1;
	if(i&&f[i-1][j][k]<=n) 
		f[i][j][k]=min(f[i][j][k],nxt[f[i-1][j][k]][a[1][i]-'a']);
	if(j&&f[i][j-1][k]<=n) 
		f[i][j][k]=min(f[i][j][k],nxt[f[i][j-1][k]][a[2][j]-'a']);
	if(k&&f[i][j][k-1]<=n)
		f[i][j][k]=min(f[i][j][k],nxt[f[i][j][k-1]][a[3][k]-'a']);
}
int main() 
{
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=0;i<26;i++) 
		lst[i]=n+1;
	for(int i=n;i>=0;i--) 
	{
		for(int j=0;j<26;++j) 
			nxt[i][j]=lst[j];
		if(i) 
			lst[s[i]-'a']=i;
	}
	while(q--) 
	{
		char opt[3],ch[3];
		int x;
		scanf("%s%d",opt,&x);
		if(opt[0]=='+') 
		{
			scanf("%s",ch);
			a[x][++len[x]]=ch[0];
			if(x==1) 
			{
				for(int i=0;i<=len[2];i++)
					for(int j=0;j<=len[3];j++)
						dp(len[x],i,j);
			}
			else if(x==2) 
			{
				for(int i=0;i<=len[1];i++)
					for(int j=0;j<=len[3];j++)
						dp(i,len[x],j);
			}
			else 
			{
				for(int i=0;i<=len[1];i++)
					for(int j=0;j<=len[2];j++)
						dp(i,j,len[x]);
			}
		}
		else 
			len[x]--;
		printf("%s\n",f[len[1]][len[2]][len[3]]<=n?"YES":"NO");
	}
	return 0;
}