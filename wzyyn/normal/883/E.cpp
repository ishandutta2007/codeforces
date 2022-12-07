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
const int M=1005,N=55;
int n,m,ans,ok[28],fl[28];
char s[M][N];
int main(){
	scanf("%d%s%d",&n,s[0]+1,&m);
	For(i,1,m) scanf("%s",s[i]+1);
	For(i,1,m){
		memset(fl,0,sizeof(fl));
		bool flg=0;
		For(j,1,n)
			if (s[0][j]=='*') fl[s[i][j]-'a']|=2;
			else if (s[0][j]!=s[i][j]) flg=1;
			else fl[s[i][j]-'a']|=1;
		For(j,0,25) if (fl[j]==3) flg=1;
		if (flg) continue;
		ans=1;
		For(j,0,25) if (fl[j]!=2) ok[j]=1; 
	}
	if (!ans) puts("0");
	else{
		ans=0;
		For(j,0,25) ans+=(!ok[j]);
		printf("%d\n",ans);
	}
}