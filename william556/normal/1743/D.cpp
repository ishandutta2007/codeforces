// LUOGU_RID: 90774792
#include<bits/stdc++.h>
using namespace std;
const int BS=1<<17;
char buf[BS],*S,*T;
inline char gc(){
	if(S==T)T=(S=buf)+fread(buf,1,BS,stdin);
	return S!=T?*(S++):EOF;
}
inline int in(){
	int x=0,f=1;char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=gc();
	return x*f;
}
const int N=1e6+5;
int n;
char s[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	int p1=0,p2=0;
	for(int i=n;i>=1;i--)if(s[i]=='1')p1=i;
	if(!p1){puts("0");return 0;}
	for(int i=n;i>=p1;i--)if(s[i]=='0')p2=i;
	string ans,s0,s1;
	for(int i=p1;i<=n;i++)s0+=s[i];
	ans=s0;
	for(int i=p1;i<p2;i++){
		if(s[i]=='0')continue;
		s1=s0;
		for(int j=0;p2+j<=n;j++){
			if(s[i+j]=='1')s1[p2-p1+j]='1';	
		}
		ans=max(ans,s1);
	}
	printf("%s\n",ans.c_str());
	return 0;
}