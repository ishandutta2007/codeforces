#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[1000];
int n,f[1000];
int main(){
	scanf("%d",&n);
	scanf("%s",ch+1); n=strlen(ch+1); int flag=0;
	for (int i=1;i<=n;i++){
		memset(f,0xff,sizeof f);
		for (int j=1;j<=n;j++) if (ch[j]=='*'){
			if (j>i&&ch[j-i]=='*') f[j]=f[j-i]+1; else f[j]=1;
			if (f[j]>=5) flag=1;
		}
	}
	if (flag) cout<<"yes"<<endl; else cout<<"no"<<endl;
	return 0;
}