#include<bits/stdc++.h>
#define N 45

int T;

int n;
char s[N],t[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			t[i]=s[i];
		std::sort(s+1,s+n+1);
		int ans=n;
		for(int i=1;i<=n;i++)
			if(s[i]==t[i])
				ans--;
		printf("%d\n",ans);
	}
}