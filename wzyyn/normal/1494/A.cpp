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

char s[55];

bool check(char c){
	int ss=0;
	for (int i=1;s[i];++i)
		if (s[i]==c) ++ss;
		else if ((--ss)<0) return 0;
	return ss==0;
}
bool check2(char c){
	int ss=0;
	for (int i=1;s[i];++i)
		if (s[i]!=c) ++ss;
		else if ((--ss)<0) return 0;
	return ss==0;
}
void solve(){
	scanf("%s",s+1);
	if (check('A')||check('B')||check('C'))
		puts("YES");
	else if (check2('A')||check2('B')||check2('C'))
		puts("YES");
	else puts("NO"); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}