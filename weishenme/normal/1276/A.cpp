#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int flag1[N],flag2[N];
int T;
char s[N];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		int ans=0,n=strlen(s+1);
		for (int i=1;i<=n-2;i++)
			if (s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')flag1[i]=1;
		for (int i=3;i<=n;i++)
			if (s[i]=='o'&&s[i-1]=='w'&&s[i-2]=='t')flag2[i]=1;
		for (int i=1;i<=n;i++)ans+=flag1[i]|flag2[i];
		printf("%d\n",ans);
		for (int i=1;i<=n;i++){
			if (flag1[i]&&flag2[i])printf("%d ",i);
			else if (flag1[i])printf("%d ",i+1);
			else if (flag2[i])printf("%d ",i-1);
			flag1[i]=flag2[i]=0;
		}
		puts("");
	} 
}