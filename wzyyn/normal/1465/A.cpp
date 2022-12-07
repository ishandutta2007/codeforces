#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
char s[105];
void solve(){
	scanf("%d%s",&n,s+1);
	int p=n;
	for (;p>=1&&s[p]==')';--p);
	puts(p<n-p?"Yes":"No");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}