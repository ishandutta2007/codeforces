#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=3505;
const int mo=1000000007;
int p,A,n,a[N];
int f[2][N][2][2];
char s[N]; 
int F(int x){
	return min(x,2*(p-1)-x)+1;
}
int main(){
	scanf("%d%d%s",&p,&A,s+1);
	n=strlen(s+1);
	reverse(s+1,s+n+1);
	For(i,1,n) s[i]-='0';
	for (;n;){
		ll x=0;
		Rep(i,n,1){
			x=x*10+s[i];
			s[i]=x/p; x%=p;
		}
		a[++*a]=x;
		for (;n&&!s[n];--n);
	}
	if (A>(*a))
		return puts("0"),0;
	memset(f,0,sizeof(f));
	int pre=0,suf=1;
	f[0][0][1][0]=1;
	For(i,1,(*a)+1){
		For(j,0,i-1) For(k,0,1) For(S,0,1){
			if (!f[pre][j][k][S]) continue;
			int val=f[pre][j][k][S];
			f[pre][j][k][S]=0;
			//printf("%d %d %d %d %d\n",i,j,k,S,val);
			For(nS,0,1){
				int v=a[i]+p*nS-S;
				int l=max(0,p*nS-S);
				int r=min(2*p-2,p*(nS+1)-1-S);
				int EQ=(v<l||v>r?0:F(v));
				int LE=1ll*(F(l)+F(v-1))*(v-l)/2%mo;
				int GE=1ll*(F(r)+F(v+1))*(r-v)/2%mo;
				//if (i==4) printf("%d %d %d %d %d %d %d\n",v,l,r,EQ,LE,GE,nS); 
				f[suf][j+nS][1][nS]=(f[suf][j+nS][1][nS]+1ll*LE*val)%mo;
				f[suf][j+nS][k][nS]=(f[suf][j+nS][k][nS]+1ll*EQ*val)%mo;
				f[suf][j+nS][0][nS]=(f[suf][j+nS][0][nS]+1ll*GE*val)%mo;
			}
		}
		swap(pre,suf);
	}
	int ans=0;
	For(i,A,*a)
		ans=(ans+f[pre][i][1][0])%mo;
	printf("%d\n",ans);
	
}
/*
f[i][j][k][l]:i,j,<=, 
*/