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
#define double long double
using namespace std;
char s[1005];
int n,ans;
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int sum=0;
	For(i,1,n) sum+=(s[i]=='0');
	int ans=sum;
	For(i,1,n){
		s[i]=='0'?sum--:sum++;
		ans=min(ans,sum);
	}
	sum=0;
	For(i,1,n) s[i]^=1;
	For(i,1,n) sum+=(s[i]=='0');
	ans=min(ans,sum);
	For(i,1,n){
		s[i]=='0'?sum--:sum++;
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}