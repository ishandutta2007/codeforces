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
const int N=105;
char s[N],ans[N];
int n,m,a[N],cnt[N];
int q[N];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	For(i,1,m) scanf("%d",&a[i]);
	memset(cnt,0,sizeof(cnt));
	For(i,1,n) cnt[s[i]-'a']++;
	int pos=25,rem=m;
	for (;rem;){
		int sum=0;
		For(i,1,m) sum+=(a[i]==0);
		for (;cnt[pos]<sum;--pos);
		For(i,1,m) if (a[i]==0) q[++*q]=i,ans[i]=pos+'a',a[i]=-1,rem--;
		for (;*q;--*q) For(i,1,m) a[i]-=abs(q[*q]-i);
		--pos;
	}
	ans[m+1]=0;
	printf("%s\n",ans+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}