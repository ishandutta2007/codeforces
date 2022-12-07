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
const int N=1000005;
char s[N],t[N];
int n,x;
void solve(){
	scanf("%s%d",s+1,&x);
	n=strlen(s+1);
	t[n+1]=0;
	For(i,1,n){
		t[i]='1';
		if (i-x>0&&s[i-x]=='0') t[i]='0';
		if (i+x<=n&&s[i+x]=='0') t[i]='0';
	}
	bool gg=0;
	For(i,1,n){
		bool vis=0;
		if (i-x>0&&t[i-x]=='1') vis=1;
		if (i+x<=n&&t[i+x]=='1') vis=1;
		if (vis!=(s[i]=='1'))
			gg=1;
	}
	if (gg) puts("-1");
	else printf("%s\n",t+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}