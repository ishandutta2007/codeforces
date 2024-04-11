#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int mo=1000000007;
const int N=2000005;
int n,Q,P[N],l[22];
int tab[100005][35];
char s[105],t[N];
char ss[22][N],tt[N];
char sss[N];
int nxt[N];
int Func(char *b,int lb,char *a,int la){
	b[lb+1]=a[la+1]=0;
	assert(lb>=la);
	nxt[1]=0;
	For(i,2,la){
		int j=nxt[i-1];
		for (;j&&a[j+1]!=a[i];j=nxt[j]);
		nxt[i]=j+(a[j+1]==a[i]);
	}
	int p=0,s=0;
	For(i,1,lb){
		for (;p&&(a[p+1]!=b[i]);p=nxt[p]);
		p+=(a[p+1]==b[i]);
		if (p==la) p=nxt[p],++s;
	}
	return s;
}
int main(){
	scanf("%d%d",&n,&Q);
	scanf("%s%s",s+1,t+1);
	P[0]=1;
	For(i,1,n) P[i]=2ll*P[i-1]%mo;
	l[0]=strlen(s+1);
	For(i,1,l[0]) ss[0][i]=s[i];
	int m=0;
	for (;l[m]<=1e6&&m!=n;){
		For(i,1,l[m]){
			ss[m+1][i]=ss[m][i];
			ss[m+1][i+l[m]+1]=ss[m][i];
		}
		ss[m+1][l[m]+1]=t[m+1];
		l[m+1]=2*l[m]+1;
		m++;
	}
	For(i,1,n){
		For(j,0,25) tab[i][j]=2ll*tab[i-1][j]%mo;
		tab[i][t[i]-'a']=(tab[i][t[i]-'a']+1)%mo;
	}
	while (Q--){
		int nn;
		scanf("%d%s",&nn,tt+1);
		int p=0,L=strlen(tt+1);
		for (;l[p]<L&&p<=m;++p);
		if (p>nn) puts("0");
		else{
			int ans=0,pos=0;
			ans=1ll*Func(ss[p],l[p],tt,L)*P[nn-p]%mo;
			For(i,l[p]-(L-1)+1,l[p]) sss[++pos]=ss[p][i];
			sss[++pos]='a';
			For(i,1,L-1) sss[++pos]=ss[p][i];
			For(i,0,25){
				sss[L]='a'+i;
				int way=(tab[nn][i]+mo-1ll*tab[p][i]*P[nn-p]%mo)%mo;
				if (way!=0) ans=(ans+1ll*way*Func(sss,2*L-1,tt,L))%mo;
			}
			printf("%d\n",ans);
		}
	}
}