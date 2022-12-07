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
int n,ans;
char s[105],t[105];
int main(){
	scanf("%d%s",&n,s+1);
	Rep(i,'z','b') For(T,1,100){
		int m=0;
		For(j,1,n){
			bool fl=0;
			if (j!=1&&s[j]==i&&s[j-1]==i-1) fl=1;
			if (j!=n&&s[j]==i&&s[j+1]==i-1) fl=1;
			if (!fl) t[++m]=s[j];
			else ++ans;
		}
		n=m; t[n+1]=0;
		memcpy(s,t,sizeof(s));
	}
	printf("%d\n",ans);
}