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
int n,a[55],v[55];
void solve(){
	scanf("%d",&n);
	memset(v,0,sizeof(v));
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) For(j,i+1,n) v[a[j]-a[i]]=1;
	int s=0;
	For(i,1,55) s+=v[i];
	cout<<s<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}