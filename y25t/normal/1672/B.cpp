#include<bits/stdc++.h>
#define N 200005

int T;

int n;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		bool f=1,g=0;
		for(int i=1,t=0;i<=n;i++){
			if(s[i]=='A')
				t++,g=0;
			else
				t--,g=1;
			if(t<0)
				f=0;
		}
		puts(f&&g?"YES":"NO");
	}
}