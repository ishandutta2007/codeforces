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
const int mo=1000000007;
const int N=2005;
char s[2][N],t[N];
int n,m,ans;
int lcs[2][N][N];
int lcp[2][N][N];
int f[N][N][2];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
void solve(bool type){
	For(k,0,1) Rep(i,n,1) Rep(j,m,1)
		lcp[k][i][j]=(s[k][i]==t[j]?lcp[k][i+1][j+1]+1:0);
	reverse(t+1,t+m+1);
	For(k,0,1) Rep(i,n,1) Rep(j,m,1)
		lcs[k][i][j]=(s[k][i]==t[j]?lcs[k][i+1][j+1]+1:0);
	reverse(t+1,t+m+1);
	memset(f,0,sizeof(f));
	For(i,1,n+1){
		For(k,0,1) f[i][1][k]=1;
		For(j,2,i-1) For(k,0,1) if (type||j*2<m)
			if (lcp[k][i-j][j+1]>=j&&lcs[k^1][i-j][m-j+1]>=j)
				UPD(f[i][2*j+1][k],1);
		For(j,1,m) For(k,0,1)
			if (i<=n&&s[k][i]==t[j]&&f[i][j][k]){
				UPD(f[i+1][j+1][k],f[i][j][k]);
				if (j+1<=m&&s[k^1][i]==t[j+1])
					UPD(f[i+1][j+2][k^1],f[i][j][k]);
				if ((m-j+1)>2&&(m-j+1)%2==0&&(type||j!=1)){
					int l=(m-j+1)/2;
					if (lcp[k][i][j]>=l&&lcs[k^1][i][1]>=l)
						UPD(ans,f[i][j][k]);
				}
			}
		UPD(ans,f[i][m+1][0]);
		UPD(ans,f[i][m+1][1]); 
	}
	//printf("%d\n",ans);
}
int main(){
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	scanf("%s",t+1);
	n=strlen(s[0]+1);
	m=strlen(t+1);
	solve(1);
	if (m>=2){
		reverse(t+1,t+m+1);
		solve(0);
	}
	if (m==2){
		For(i,1,n){
			if (s[0][i]==t[1]&&s[1][i]==t[2])
				UPD(ans,mo-1);
			if (s[0][i]==t[2]&&s[1][i]==t[1])
				UPD(ans,mo-1);
		}
	}
	printf("%d\n",ans);
}