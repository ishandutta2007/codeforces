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
const int N=10005;
char s[N],t[N];
int n,m,f[N][N];
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	memset(f,60,sizeof(f));
	f[0][0]=0;
	For(i,1,n){
		For(j,0,m){
			f[i][j]=min(f[i][j],f[i-1][j]+1);
			if (s[i]==t[j+1]) f[i][j+1]=min(f[i][j+1],f[i-1][j]);
		}
		if (s[i]!='.'){
			int p=i,sum=0;
			for (;p<=n;++p){
				sum+=(s[p]=='.'?-1:1);
				if (!sum) break;
			}
			if (sum) continue;
			For(j,0,m) f[p][j]=min(f[p][j],f[i-1][j]);
		}
	}
	cout<<f[n][m]<<endl;
}