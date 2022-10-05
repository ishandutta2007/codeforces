#include<bits/stdc++.h>
using namespace std;
int n,last=1,tot=1;
char s[110000];
int len[210000];
int link[210000];
int ne[210000][26]={};
vector<int> ch[210000];
int f[210000]={};
void cal(int i){
	for(int j=0;j<ch[i].size();j++){
		cal(ch[i][j]);
		f[i]+=f[ch[i][j]];
	} 
}
int main(){
	scanf("%s",s);
	n=strlen(s);
	len[1]=link[1]=0;
	for(int i=0;i<n;i++){
		int c=s[i]-'a';
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
	for(int i=0;i<n;i++){
		o=ne[o][s[i]-'a'];
		f[o]=1;
	}
	for(int i=2;i<=tot;i++) ch[link[i]].push_back(i);
	cal(1);
	long long ans=0;
	for(int i=2;i<=tot;i++) ans+=(((long long)f[i]*(f[i]+1))/2)*(len[i]-len[link[i]]);
	cout<<ans;
	return 0;
}