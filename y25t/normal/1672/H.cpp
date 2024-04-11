#include<bits/stdc++.h>
#define N 200005

int n,q;
char str[N];

int s[N][2];

int main(){
	scanf("%d%d%s",&n,&q,str+1);
	for(int i=2;i<=n;i++){
		s[i][0]=s[i-1][0],s[i][1]=s[i-1][1];
		if(str[i]==str[i-1])
			s[i][str[i]-'0']++;
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",std::max(s[r][0]-s[l][0],s[r][1]-s[l][1])+1);
	}
}