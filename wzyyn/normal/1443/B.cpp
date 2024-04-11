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
int a,b;
char s[100005];
void solve(){
	scanf("%d%d%s",&a,&b,s+1);
	bool pref=0;
	int ans=0,fl=0;
	int n=strlen(s+1);
	For(i,1,n)
		if (s[i]=='1'){
			if (s[i-1]!='1') ans+=a;
			if (s[i-1]=='0'&&pref)
				if (fl*b<a) ans+=fl*b-a;
			pref=1; fl=0;
		}
		else
			++fl;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}