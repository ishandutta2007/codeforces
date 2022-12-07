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
const int N=5005;
char s[N],t[N],ans[N];
int n;
void solve(){
	scanf("%d%s",&n,s+1);
	memcpy(ans,s,sizeof(s));
	int id=1;
	For(i,1,n){
		int top=0;
		For(j,i,n) t[++top]=s[j];
		For(j,1,i-1) t[++top]=s[j];
		t[top+1]=0;
		if ((n-i+1)&1) reverse(t+n-i+2,t+top+1);
		bool flg=0;
		For(j,1,n)
			if (t[j]!=ans[j]){
				flg=(t[j]<ans[j]);
				break;
			}
		//printf("%s\n",t+1);
		if (flg){
			id=i;
			memcpy(ans,t,sizeof(ans));
		}
	}
	printf("%s\n%d\n",ans+1,id);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}