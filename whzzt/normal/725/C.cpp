#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
#define D(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
char s[60];int vis[300],lp,rp;
char ans[2][20];
int main(){
	scanf("%s",s);
	memset(vis,-1,sizeof(vis));
	F(i,0,26){
		if(vis[s[i]]!=-1)
			lp=vis[s[i]],rp=i;
		vis[s[i]]=i;
	}
	F(i,27,52)s[i]=s[i-27];
	if(lp==rp-1) puts("Impossible");
	else {
		int beg=(rp-lp+1)>>1,tot=lp;
		D(i,beg,1){
			if(tot==rp)tot++;
			ans[0][i]=s[tot++];
		}
		F(i,1,13){
			if(tot==rp)tot++;
			ans[1][i]=s[tot++];
		}
		D(i,13,beg+1){
			if(tot==rp)tot++;
			ans[0][i]=s[tot++];
		}
	}
	puts(ans[0]+1);
	puts(ans[1]+1);
	return 0;
}