#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=5005;
int cnt1[10],cnt2[10];
char s[N],t[N];
int n,ans[N],fl;
void work(int x){
	if (x==0) return;
	ans[++*ans]=x;
	reverse(s+1,s+x+1);
}
void solve(){
	*ans=0;
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	For(i,1,n) s[i]&=1,t[i]&=1;
	for (int i=1;i<=n;i+=2) cnt1[s[i]*2+s[i+1]]++;
	for (int i=1;i<=n;i+=2) cnt2[t[i]*2+t[i+1]]++;
	if (cnt1[0]!=cnt2[0]||cnt1[3]!=cnt2[3])
		return puts("-1"),void(0);
	int s1=cnt1[1]-cnt1[2],s2=cnt2[1]-cnt2[2];
	if (abs(s1)<abs(s2))
		swap(s,t),fl=1;
	else fl=0;
	if (s1!=-s2)
		for (int i=1,S=0;i<=n;i+=2){
			if (s[i]==0&&s[i+1]==1) ++S;
			if (s[i]==1&&s[i+1]==0) --S;
			if (s1-2*S==-s2){
				work(i+1);
				break;
			}
		}
	for (int i=1;i<=n;i+=2)
		for (int j=i;j<=n;j+=2)
			if (s[j+1]==t[n-i]&&s[j]==t[n-i+1]){
				work(j-1); work(j+1); break;
			}
	if (fl) reverse(ans+1,ans+*ans+1);
	printf("%d\n",ans[0]);
	For(i,1,*ans) printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}