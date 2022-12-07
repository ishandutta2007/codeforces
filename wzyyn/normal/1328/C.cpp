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

const int N=50005;
int n;
char s[N],s1[N],s2[N];
void solve(){
	scanf("%d%s",&n,s+1);
	s1[n+1]=s2[n+1]=0;
	bool flg=0;
	For(i,1,n)
		if (flg) s1[i]='0',s2[i]=s[i];
		else if (s[i]=='1') s1[i]='1',s2[i]='0',flg=1;
		else s1[i]=s2[i]='0'+(s[i]-'0')/2;
	printf("%s\n%s\n",s1+1,s2+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}