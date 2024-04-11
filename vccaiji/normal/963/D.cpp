#include<bits/stdc++.h>
using namespace std;
int n;
char ss[110000];
int kk[110000];
vector<int> c[110000];
char s[110000];
int ch[210000][26]={};
int tot=1;
int q[2100000];
int be=1,en=0;
int fl[2100000];
int num[2100000]={};
//bool done[21000000]={};
int ffl[2100000];
int sss[2100000];
int main(){
	scanf("%s",ss);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&kk[i],s);
		int m=strlen(s);
		sss[i]=m;
		int k=1;
		for(int j=0;j<m;j++){
			int u=s[j]-'a';
			if(ch[k][u]==0) ch[k][u]=++tot;
			k=ch[k][u];
		}
		num[k]=i;
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
	int m=strlen(ss);
	int k=1;
	ffl[1]=1;
    for(int i=1;i<=en;i++){
    	if(num[fl[q[i]]])ffl[q[i]]=fl[q[i]];
    	else ffl[q[i]]=ffl[fl[q[i]]];
	}
	for(int i=0;i<m;i++){
		k=ch[k][ss[i]-'a'];
		for(int j=k;j>1;j=ffl[j])c[num[j]].push_back(i);
    }
    for(int i=1;i<=n;i++){
    	if(c[i].size()<kk[i])printf("-1\n");
    	else{
    		int ans=1100000;
    		int o=(int)c[i].size()-kk[i];
    		for(int j=0;j<=o;j++)ans=min(ans,c[i][j+kk[i]-1]-c[i][j]);
    	    printf("%d\n",ans+sss[i]);
		}
	}
//    int ans=0;
//    for(int i=en;i>=1;i--){
//    	k=q[i];
//    	if(done[k]) done[fl[k]]=1;
//    	if(done[k]) ans+=num[k];
//	}
//	cout<<ans;
	return 0;
}
/*
aaabbbbaaabababab
3
2 aaabbbbaaaba
2 baaabab
1 abbbbaaabab
*/