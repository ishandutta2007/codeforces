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
char s[1<<18];
int cnt(char d,int l,int r){
	if (l==r) return (s[l]!=d);
	int mid=(l+r)/2;
	int s1=cnt(d+1,l,mid),s2=cnt(d+1,mid+1,r);
	For(i,mid+1,r) s1+=(s[i]!=d);
	For(i,l,mid) s2+=(s[i]!=d);
	return min(s1,s2);
}
void solve(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	printf("%d\n",cnt('a',1,n));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}