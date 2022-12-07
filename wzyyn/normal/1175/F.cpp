#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;

ull rnd(){
	static ull A=534289562384793132ull;
	static ull B=123789571290518103ull;
	static ull C=574315680931845710ull;
	static ull D=582190571202109013ull;
	ull tmp=A^B^C^D;
	A^=B>>8; B^=C<<3; C^=D>>5; D^=tmp<<7;
	return tmp;
}
const int N=300005;
int n,ans,b[N];
ull a[N],sa[N],sb[N];
void work(int p){
	int mx=1;
	for (;p<n&&b[p+1]!=1;){
		mx=max(mx,b[p+1]); ++p;
		if (mx<=p&&sa[mx]==(sb[p]^sb[p-mx])) ++ans;
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,10000) rnd();
	For(i,1,n) a[i]=rnd(),sa[i]=sa[i-1]^a[i];
	For(i,1,n) scanf("%d",&b[i]);
	For(T,1,2){
		For(i,1,n) sb[i]=sb[i-1]^a[b[i]];
		For(i,1,n) if (b[i]==1){
			if (T==1) ++ans;
			work(i);
		}
		reverse(b+1,b+n+1);
	}
	printf("%d\n",ans);
}