#include<bits/stdc++.h>
using namespace std;
int n,d;
char s[110000],t[21000];
int ch[210000][26]={};
int tot=1;
int q[210000];
int be=1,en=0;
int fl[210000];
int num[2100000]={};
bool done[2100000]={};
char x[60];
const int p=1000000007;
void init(){
	n=strlen(s);
	for(int i=1;i<=n-d/2+1;i++){
		int m=d/2,k=1;
		for(int j=0;j<m;j++){
			int u=s[j+i-1]-'0';
			if(ch[k][u]==0) ch[k][u]=++tot;
			k=ch[k][u];
		}
		num[k]++;
    }
	for(int i=0;i<26;i++){
		if(ch[1][i]){
			q[++en]=ch[1][i];
			fl[ch[1][i]]=1;
		}
		else ch[1][i]=1;
	}
	while(be<=en){
		int o=q[be++];
		for(int i=0;i<26;i++){
			if(ch[o][i]){
				q[++en]=ch[o][i];
				fl[ch[o][i]]=ch[fl[o]][i];
			}
			else ch[o][i]=ch[fl[o]][i];
		}
	}
}
int o[60][51000];
int solve(){
	int u=1;
	for(int k=0;k<=d;k++,u=10ll*u%p)for(int i=1;i<=tot;i++){
		if(num[i])o[k][i]=u;
		else{
			o[k][i]=0;
			if(k)for(int q=0;q<10;q++)o[k][i]=(o[k][i]+o[k-1][ch[i][q]])%p;
		}
	}
	int ans=0;
	u=1;
	for(int i=0;i<d;i++){
		if(num[u]){
			for(int k=0,uu=1;k<=d-i-1;k++,uu=10ll*uu%p)ans=(ans+1ll*uu*(x[d-k-1]-'0'))%p;
			return (ans+1)%p;
		}
		for(int q=0;q<x[i]-'0';q++)ans=(ans+o[d-i-1][ch[u][q]])%p;
		u=ch[u][x[i]-'0'];
	}
	if(num[u])ans=(ans+1)%p;
	return ans;
}
int main(){
	scanf("%s",s);
	scanf("%s",x);
	d=strlen(x);
	for(int i=d-1;i>=0;i--)if(x[i]!='0'){
		for(int j=d-1;j>i;j--)x[j]='9';
		x[i]=x[i]-1;
		break;
	}
	init();
	int a=solve();
	scanf("%s",x);
	cout<<(solve()+p-a)%p;
	return 0;
}
/*
8951675223927155592759982402444004111663484015769374476127117887584934467757214664482684650548798755
114243
233232
*/