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
char s[N];
int n,ans,q[N];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	For(i,1,n){
		int f1=0,f2=0;
		f1=(i>=3&&s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o');
		f2=(i<=n-2&&s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e');
		if (f1&&f2) q[++ans]=i;
		else if (f1) q[++ans]=i-1;
		else if (f2) q[++ans]=i+1;
	}
	printf("%d\n",ans);
	For(i,1,ans) printf("%d ",q[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}