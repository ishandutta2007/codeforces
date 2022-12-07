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
char s[100];
void solve(){
	scanf("%s",s+1);
	for (int i=1;s[i];++i)
		if (i&1) s[i]=(s[i]=='a'?'b':'a');
		else s[i]=(s[i]=='z'?'y':'z');
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}