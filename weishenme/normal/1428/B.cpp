#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int T,n;
char s[N];
int main(){
	scanf("%d",&T);
	while (T--){
		int flag1=0,flag2=0;
		scanf("%d",&n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)flag1|=s[i]=='>',flag2|=s[i]=='<';
		if (flag1&&flag2){
			int ans=0;
			for (int i=1;i<=n;i++)
				if (s[i]=='-'||s[i==1?n:i-1]=='-')ans++;
			printf("%d\n",ans);
			continue;
		}
		printf("%d\n",n);
	}
}