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

char s[1005];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	For(i,1,n) s[i]='a';
	For(i,k,n) s[i]='a'+(i-k)%3;
	s[n+1]=0;
	printf("%s\n",s+1); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}