#include<bits/stdc++.h>
#define N 200005

int T;

int n;
char s[N];

int c0,c1,lst[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		c0=0,c1=0;
		for(int i=1;i<=n;i++)
			(s[i]=='0'?c0:c1)++;
		if(c0<c1){
			std::reverse(s+1,s+n+1);
			for(int i=1;i<=n;i++)
				s[i]^='0'^'1';
		}
		c0=c1=0;
		for(int i=1;i<=n;i++)
			lst[i]=0;
		for(int i=1;i<=n;i++){
			(s[i]=='0'?c0:c1)++;
			if(c0>=c1)
				lst[c0-c1]=c0;
		}
		int x=0;
		while(x<n&&s[x+1]=='0')
			x++;
		if(x==c0){
			puts("0");
			continue;
		}
		int res=0;
		while(c0-x>c1)
			res++,x=lst[x];
		printf("%d\n",res+1);
	}
}