#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n;
int q1[200005];
int q2[200005];
char s[200005];
char ans[200005];
void solve(){
	scanf("%d%s",&n,s+1);
	For(chr,'0','9'){
		For(i,1,n) ans[i]=0;
		int t1=0,t2=0;
		For(i,1,n) if (s[i]<=chr){
			for (;t1&&s[q1[t1]]>s[i];--t1);
			q1[++t1]=i;
		}
		Rep(i,n,1) if (s[i]>=chr){
			for (;t2&&s[q2[t2]]<s[i];--t2);
			q2[++t2]=i;
		}
		For(i,1,t1) ans[q1[i]]=1;
		For(i,1,t2) ans[q2[i]]=2;
		bool flag=0;
		For(i,1,n) if (!ans[i]) flag=1;
		if (!flag){
			For(i,1,n) printf("%d",ans[i]);
			puts("");
			return;
		}
	}
	puts("-");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}