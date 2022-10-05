#include<bits/stdc++.h>//hihi
using namespace std;
int n,m,last=1,tot=1;
char s[110000];
char t[110000];
int len[210000];
int link[210000];
int ne[210000][27]={};
vector<int> ch[210000];
int f[210000]={};
int g[210000]={};
int h[210000]={};
void cal(int i){
	for(int j=0;j<ch[i].size();j++){
		cal(ch[i][j]);//luogu
		f[i]+=f[ch[i][j]];
		g[i]+=g[ch[i][j]];
		h[i]+=h[ch[i][j]];
	} 
}
int main(){
	scanf("%s%s",s,t);
	n=strlen(s);
	m=strlen(t);
	len[1]=link[1]=0;
	for(int i=0;i<n+m+1;i++){
		int c;
		if(i<n) c=s[i]-'a';
		if(i==n) c=26;
		if(i>n) c=t[i-n-1]-'a';
		int cur=++tot;
		len[cur]=len[last]+1;
		int p=last;
		for(;p;p=link[p]){
			if(ne[p][c]) break;
			ne[p][c]=cur;
		}
		if(p==0){
			link[cur]=1;
			last=cur;
			continue;
		}
		int q=ne[p][c];
		if(len[q]==len[p]+1){
			link[cur]=q;
			last=cur;
			continue;
		}
		int clone=++tot;
		len[clone]=len[p]+1;
		link[clone]=link[q];
		for(int j=0;j<26;j++) ne[clone][j]=ne[q][j];
		for(;p;p=link[p]){
			if(ne[p][c]==q) ne[p][c]=clone;
			else break;
		}
		link[q]=link[cur]=clone;
        last=cur;
	}
	int o=1;
	f[o]=1;
	for(int i=0;i<n+m+1;i++){
		int c;
		if(i<n) c=s[i]-'a';
		if(i==n) c=26;
		if(i>n) c=t[i-n-1]-'a';
		o=ne[o][c];
		f[o]=1;
		if(i<n) g[o]=1;
		if(i>n) h[o]=1;
	}
	for(int i=2;i<=tot;i++) ch[link[i]].push_back(i);
	cal(1);
	int ans=100000000;
	for(int i=2;i<=tot;i++) if((g[i]==1)&&(h[i]==1)&&(f[i]==2)) ans=min(ans,len[link[i]]+1);
	cout<<(ans==100000000 ? -1 : ans);
	return 0;
}