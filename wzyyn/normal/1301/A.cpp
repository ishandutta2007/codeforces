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
char s1[105],s2[105],s3[105];
void solve(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	scanf("%s",s3+1);
	int n=strlen(s1+1);
	For(i,1,n)
		if (s1[i]!=s3[i]&&s2[i]!=s3[i])
			return puts("NO"),void(0);
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}