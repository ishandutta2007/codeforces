#include<bits/stdc++.h>
#define LL __uint128_t

int m;
char s[50];

int n;
LL f;

inline LL mul(LL x,LL y){
	LL res=0;
	for(int i=0;i<n;i++) if((y>>i)&1)
		res^=x<<i;
	for(int i=n+n-2;i>=n;i--) if((res>>i)&1)
		res^=f<<(i-n);
	return res;
}

std::map<LL,int> vis;

int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++) if(s[i]=='1'){
		for(int j=i;j<=len;j++) if(s[j]=='1')
			f|=(LL)1<<(j-i),n=j-i;
		m=i;
		break;
	}
	if(!m)
		return puts("-1"),0;
	if(!n)
		return printf("%d %d\n",m,m+1),0;
	LL x=1;
	for(int i=0;i<(1<<17);i++,x=mul(x,2))
		vis[x]=i;
	LL y=x;
	for(int i=1;i<=(1<<17);i++,x=mul(x,y)) if(vis.count(x))
		return printf("%d %lld\n",m,m+((long long)i<<17)-vis[x]),0;
}