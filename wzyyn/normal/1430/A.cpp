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

void solve(){
	int n;
	scanf("%d",&n);
	For(i,0,n/5) For(j,0,(n-5*i)/7)
		if ((n-5*i-7*j)%3==0){
			cout<<(n-5*i-7*j)/3<<' '<<i<<' '<<j<<endl;
			return; 
		}
	cout<<-1<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}