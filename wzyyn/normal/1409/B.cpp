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

ll F(int a,int b,int x,int y,int n){
	
	int v=min(b-y,n); n-=v; b-=v;
	v=min(a-x,n); n-=v; a-=v;
	return 1ll*a*b;
}
void solve(){
	int a,b,x,y,n;
	cin>>a>>b>>x>>y>>n;
	cout<<min(F(a,b,x,y,n),F(b,a,y,x,n))<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}