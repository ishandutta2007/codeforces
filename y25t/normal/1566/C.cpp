#include<bits/stdc++.h>
#define N 100005

int T;

int n;
char s[N],t[N];

int pre[N][2],lst[2];

int f[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,s+1,t+1);
		lst[0]=lst[1]=0;
		for(int i=1;i<=n;i++){
			lst[s[i]-'0']=lst[t[i]-'0']=i;
			pre[i][0]=lst[0],pre[i][1]=lst[1];
		}
		f[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			if(pre[i][0])
				f[i]=std::max(f[i],f[pre[i][0]-1]+1);
			if(std::min(pre[i][0],pre[i][1]))
				f[i]=std::max(f[i],f[std::min(pre[i][0],pre[i][1])-1]+2);
		}
		printf("%d\n",f[n]);
	}
}