#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;


int n;
char s[500005];
char t1[500005];
char t2[500005];
void solve(){
	scanf("%d%s",&n,s+1);
	int s0=0,s1=0;
	for (int i=1;i<=n;i++)
		s[i]=='1'?++s0:++s1;
	int ss0=0,ss1=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='1'){
			++ss0;
			t1[i]=(ss0*2<=s0?'(':')');
			t2[i]=t1[i];
		}
		else{
			++ss1;
			t1[i]=(ss1&1?'(':')');
			t2[i]=t1[i]^')'^'(';
		}
	ss0=0,ss1=0;
	for (int i=1;i<=n;i++){
		ss0+=(t1[i]=='('?1:-1);
		ss1+=(t2[i]=='('?1:-1);
		if (ss0<0||ss1<0)
			return puts("NO"),void(0);
	}
	t1[n+1]=t2[n+1]=0;
	puts("YES");
	printf("%s\n",t1+1);
	printf("%s\n",t2+1); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}