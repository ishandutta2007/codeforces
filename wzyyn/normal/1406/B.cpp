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
ll mn[10],mx[10];
int n;
void solve(){
	scanf("%d",&n);
	For(i,0,5){
		mn[i]=(1ll<<60);
		mx[i]=-(1ll<<60);
	}
	mn[0]=mx[0]=1;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		Rep(j,min(4,i-1),0){
			mx[j+1]=max(mx[j+1],max(mx[j]*x,mn[j]*x));
			mn[j+1]=min(mn[j+1],min(mn[j]*x,mx[j]*x));
		}
	}
	cout<<mx[5]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}