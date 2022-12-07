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

void solve(){
	int n,mn=1e9,mns=0,x;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&x);
		if (x<mn) mn=x,mns=0;
		if (x==mn) ++mns;
	}
	cout<<n-mns<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}