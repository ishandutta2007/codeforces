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
char s[200005];
void solve(){
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	int ss=0,fl=1,ans=0; k++;
	For(i,1,n+1)
		if (i==n+1||s[i]=='1'){
			ss-=k-1;
			if (i==n+1) ss+=k-1;
			if (fl==1) ss+=k-1;
			ans+=ss/k; ss=0; fl=0;
		}
		else ++ss;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}