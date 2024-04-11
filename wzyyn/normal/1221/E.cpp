#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=300005;
int a,b,q[N];
int sa,sb,sc;
char s[N];
void add(int x){
	if (!x) return;
	if (x>=2*b) ++sc;
	else if (x>=a) ++sa;
	else if (x>=b) ++sb;
}
void dec(int x){
	if (!x) return;
	if (x>=2*b) --sc;
	else if (x>=a) --sa;
	else if (x>=b) --sb;
}
void solve(){
	scanf("%d%d%s",&a,&b,s+1);
	int n=strlen(s+1),pre=*q=0;
	sa=sb=sc=0;
	For(i,1,n+1)
		if (s[i]=='X'||i==n+1){
			q[++*q]=i-pre-1;
			pre=i;
		}
	sort(q+1,q+*q+1);
	bool flag=0;
	For(i,1,*q) add(q[i]);
	For(i,1,*q) For(j,0,q[i]-a){
		add(j); add(q[i]-a-j); dec(q[i]);
		if (!sb&&!sc&&sa%2==0) flag=1;
		dec(j); dec(q[i]-a-j); add(q[i]);
	}
	puts(flag?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}