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
int n,Q,k,a[100005];
int main(){
	scanf("%d%d%d",&n,&Q,&k);
	For(i,1,n) scanf("%d",&a[i]);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int re=2*k-2*(r-l+1)-(a[l]-1)-(k-a[r]);
		cout<<re<<endl;
	}
}