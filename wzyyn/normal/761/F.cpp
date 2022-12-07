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
const int N=1005;
const int M=300005;
char s[N][N],t[10];
int c[M],lx[M],ly[M];
int n,m,Q,rx[M],ry[M];
ll T[N][N],S[26][N][N];
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,Q){
		scanf("%d%d%d%d%s",&lx[i],&ly[i],&rx[i],&ry[i],t+1);
		c[i]=t[1]-'a';
		++S[t[1]-'a'][lx[i]][ly[i]];
		--S[t[1]-'a'][lx[i]][ry[i]+1];
		--S[t[1]-'a'][rx[i]+1][ly[i]];
		++S[t[1]-'a'][rx[i]+1][ry[i]+1];
	}
	For(i,0,25){
		For(j,1,n) For(k,1,m) S[i][j][k]+=S[i][j-1][k];
		For(j,1,n) For(k,1,m) S[i][j][k]+=S[i][j][k-1];
	}
	//cout<<233<<endl;
	For(i,1,n) For(j,1,m){
		int c=s[i][j]-'a',SS=Q;
		For(k,0,25) SS-=S[k][i][j];
		S[c][i][j]+=SS;
		For(k,0,25) T[i][j]+=abs(c-k)*S[k][i][j];
	}
	//cout<<233<<endl;
	For(i,1,n) For(j,1,m) T[i][j]+=T[i][j-1];
	For(i,1,n) For(j,1,m) T[i][j]+=T[i-1][j];
	For(i,0,25){
		For(j,1,n) For(k,1,m) S[i][j][k]+=S[i][j-1][k];
		For(j,1,n) For(k,1,m) S[i][j][k]+=S[i][j][k-1];
	}
	//cout<<233<<endl;
	ll res=1ll<<60;
	For(i,1,Q){
		ll ans=T[n][m];
		ans-=T[rx[i]][ry[i]];
		ans+=T[lx[i]-1][ry[i]];
		ans+=T[rx[i]][ly[i]-1];
		ans-=T[lx[i]-1][ly[i]-1];
		For(j,0,25){
			ll sum=0;
			sum+=S[j][rx[i]][ry[i]];
			sum-=S[j][lx[i]-1][ry[i]];
			sum-=S[j][rx[i]][ly[i]-1];
			sum+=S[j][lx[i]-1][ly[i]-1];
			ans+=abs(j-c[i])*sum;
		}
		res=min(res,ans);
	}
	printf("%lld\n",res);
}