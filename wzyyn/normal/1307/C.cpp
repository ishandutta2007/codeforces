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
char s[100005];
ll S[26],SS[26][26];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n){
		int c=s[i]-'a';
		For(j,0,25) SS[j][c]+=S[j];
		++S[c];
	}
	ll ans=0;
	For(i,0,25) ans=max(ans,S[i]);
	For(i,0,25) For(j,0,25) ans=max(ans,SS[i][j]);
	cout<<ans<<endl;
}