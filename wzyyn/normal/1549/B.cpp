#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
int n;
char s[200005];
char t[200005];
void solve(){
	scanf("%d",&n);
	scanf("%s",t+1);
	scanf("%s",s+1);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='1'&&t[i]=='0') ++ans,s[i]='0';
	for (int i=1;i<=n;i++)
		if (s[i]=='1'){
			if (i-1>=0&&t[i-1]=='1') t[i-1]='0',++ans;
			else if (i+1<=n&&t[i+1]=='1') t[i+1]='0',++ans;
		}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}