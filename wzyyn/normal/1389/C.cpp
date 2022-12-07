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
const int N=200005;
char s[N];
int n,su[N][10];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,0,9) su[n+1][i]=n+1;
	Rep(i,n,1) For(j,0,9)
		su[i][j]=(s[i]==j+'0'?i:su[i+1][j]);
	int ans=0;
	For(i,0,9) For(j,0,9){
		int x=1,t=0;
		for (;;){
			if (su[x][i]==n+1) break;
			x=su[x][i]+1; ++t;
			if (su[x][j]==n+1) break;
			x=su[x][j]+1; ++t;
		}
		if (i!=j) t=t/2*2;
		ans=max(ans,t);
	}
	cout<<n-ans<<endl;
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}