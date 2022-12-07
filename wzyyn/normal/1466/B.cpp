#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
void solve(){
	scanf("%d",&n);
	For(i,1,2*n+1) a[i]=b[i]=0; 
	int ans=0;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		++a[x];
	}
	For(i,1,2*n){
		if (!b[i]&&a[i]) b[i]=1,ans++,a[i]--;
		if (!b[i+1]&&a[i]) b[i+1]=1,ans++;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}