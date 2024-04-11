#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int pr[N][26],su[N][26];
int prv[N][26],suv[N][26];
int n,Q,S[N];
char s[N];
pii q[N*2];
int Calc(int l,int r){
	int sta=0;
	For(i,0,25) if (pr[r][i]>=l){
		int w=S[su[l][i]]^S[pr[r][i]];
		w^=suv[l][i]^prv[r][i];
		sta|=1<<w;
	}
	int ans=0;
	for (;sta&(1<<ans);++ans);
	return ans;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n) s[i]-='a';
	For(j,0,25) pr[0][j]=0;
	For(i,1,n) For(j,0,25)
		pr[i][j]=(s[i]==j?i:pr[i-1][j]);
	For(j,0,25) su[n+1][j]=n+1;
	Rep(i,n,1) For(j,0,25)
		su[i][j]=(s[i]==j?i:su[i+1][j]);
	For(i,1,n){
		int top=0;
		S[i]=S[pr[i-1][s[i]]]^prv[i-1][s[i]];
		//cout<<prv[i-1][s[i]]<<endl;
		For(j,0,25)
			if (pr[i][j]&&j!=s[i])
				q[++top]=pii(pr[i][j]+1,0);
		if (i!=n)
			For(j,pr[i][s[i+1]]+1,i)
				q[++top]=pii(j,1);
		sort(q+1,q+top+1,greater<pii >());
		For(j,1,top)
			if (q[j].se==0)
				prv[i][s[q[j].fi-1]]=Calc(q[j].fi,i);
			else suv[q[j].fi][s[i+1]]=Calc(q[j].fi,i);
	}
	scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		//cout<<Calc(l,r)<<endl;
		puts(Calc(l,r)?"Alice":"Bob");
	}
}