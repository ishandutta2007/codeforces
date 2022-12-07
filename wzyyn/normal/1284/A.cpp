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
int n,m,Q;
string s[25],t[25];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) cin>>s[i];
	For(i,1,m) cin>>t[i];
	scanf("%d",&Q);
	while (Q--){
		int x;
		scanf("%d",&x);
		cout<<s[(x-1)%n+1];
		cout<<t[(x-1)%m+1];
		cout<<endl;
	}
}