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
const int N=100005;
bitset<N> b[26],all,ans,bas;
char s[N],t[N];
int n,Q;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n) b[s[i]-'a'][i]=1;
	For(i,1,n) all[i]=1;
	scanf("%d",&Q);
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int x;
			scanf("%d%s",&x,t+1);
			b[s[x]-'a'][x]=0;
			b[(s[x]=t[1])-'a'][x]=1;
		}
		else{
			int l,r;
			scanf("%d%d%s",&l,&r,t+1);
			ans=bas=(all<<(l-1))&(all>>(n-r));
			//For(i,1,n) putchar(ans[i]?'Y':'N'); puts("");//assert(ans[i]);
			int len=strlen(t+1);
			For(i,1,len) ans&=(b[t[i]-'a']&bas)>>(i-1);
			printf("%d\n",ans.count());
		}
	}
}