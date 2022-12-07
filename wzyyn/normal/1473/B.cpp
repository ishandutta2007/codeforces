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

char s[25],t[25];
void solve(){
	scanf("%s%s",s,t);
	int l1=strlen(s);
	int l2=strlen(t);
	For(i,0,l1*l2-1)
		if (s[i%l1]!=t[i%l2]) break;
		else if (i%l1==l1-1&&i%l2==l2-1){
			For(j,0,i) putchar(s[j%l1]); puts("");
			//For(j,0,l2-1) putchar(t[j%l2]); puts("");
			return;
		}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}