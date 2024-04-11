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
const int N=1005;
int pos[N],vis[N];
char ans[N],s[N];
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	memset(pos,0,sizeof(pos));
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	int l=50,r=50,p=50;
	ans[50]=s[1]; pos[s[1]]=50;
	For(i,2,n)
		if (!pos[s[i]]){
			int np;
			if (p==l&&!ans[l-1]) np=--l;
			else if (p==r&&!ans[r+1]) np=++r;
			else return puts("NO"),void(0);
			ans[np]=s[i]; pos[s[i]]=np; p=np;
		}
		else{
			//cout<<i<<endl;
			if (abs(pos[s[i]]-p)!=1)
				return puts("NO"),void(0);
			p=pos[s[i]];
		}
	puts("YES");
	For(i,l,r) putchar(ans[i]);
	For(i,0,25) if (!pos['a'+i]) putchar('a'+i);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}