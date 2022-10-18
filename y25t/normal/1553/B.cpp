#include<bits/stdc++.h>
#define N 5005

int T;

int n,m;
char s[N],t[N];

char ss[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		bool flg=0;
		for(int i=1;i<=n;i++)
			for(int j=1;i+j-1<=n&&j<=m;j++){
				int p=0;
				for(int k=1;k<=j;k++)
					ss[++p]=s[i+k-1];
				for(int k=i+j-2;k&&p<m;k--)
					ss[++p]=s[k];
				if(p<m)
					continue;
				bool f=1;
				for(int k=1;k<=m;k++)
					if(ss[k]!=t[k])
						f=0;
				if(f)
					flg=1;
			}
		puts(flg?"YES":"NO");
	}
}