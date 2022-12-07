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
const int N=1000005;
int n,x,p1[N],p2[N],s[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&x),p1[x]=i;
	For(i,1,n) scanf("%d",&x),p2[x]=i;
	For(i,0,n-1) s[i]=0;
	For(i,1,n) ++s[(p1[i]+n-p2[i])%n];
	For(i,0,n-1) s[0]=max(s[0],s[i]);
	cout<<s[0]<<endl;
}
int main(){
	solve();
}