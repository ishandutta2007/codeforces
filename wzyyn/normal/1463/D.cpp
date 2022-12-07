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
const int N=400005;
int n,v[N],a[N],b[N];
void solve(){
	scanf("%d",&n);
	For(i,1,2*n) v[i]=0;
	For(i,1,n) scanf("%d",&a[i]),v[a[i]]=1;
	*b=0;
	For(i,1,2*n) if (!v[i]) b[++*b]=i;
	int l=n,r=n;
	For(i,1,n){
		int p=lower_bound(b+1,b+*b+1,a[i])-b;
		r=min(r,(n-i+1)+(p-1)-1);
		l=min(l,(*b-p)+i);
		//cout<<i<<' '<<p<<endl;
	}
	cout<<max(0,r+l+1-n)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}