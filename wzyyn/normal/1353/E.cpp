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
int n,k;
char s[1000005];
void solve(){
	int sum=0,v=0;
	scanf("%d%d%s",&n,&k,s+1);
	For(i,1,n) sum+=(s[i]=='1');
	For(i,1,k){
		int ss=0,mn=0;
		for (int j=i;j<=n;j+=k){
			s[j]=='1'?++ss:--ss;
			v=max(v,ss-mn);
			mn=min(mn,ss);
		}
	}
	printf("%d\n",sum-v);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}