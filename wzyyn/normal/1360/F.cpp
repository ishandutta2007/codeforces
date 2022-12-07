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
int n,m;
char s[15][15];
char ans[15];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	memset(ans,0,sizeof(ans));
	For(j,1,m) For(c,'a','z'){
		memcpy(ans,s[1],sizeof(ans)); ans[j]=c;
		bool flag=0;
		For(p,1,n){
			int sum=0;
			For(q,1,m) sum+=(ans[q]!=s[p][q]);
			if (sum>1) flag=1;
		}
		if (!flag){
			printf("%s\n",ans+1);
			return;
		}
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}