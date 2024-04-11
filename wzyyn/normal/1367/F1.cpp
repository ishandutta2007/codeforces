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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=200005;
int n,a[N],b[N],m,pr[N],su[N];
vector<int> vec[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),b[i]=a[i];
	sort(a+1,a+n+1);
	m=unique(a+1,a+n+1)-a-1;
	For(i,1,n) b[i]=lower_bound(a+1,a+m+1,b[i])-a;
	For(i,1,m) vec[i].resize(0);
	For(i,1,n) vec[b[i]].PB(i);
	int ans=0;
	//cerr<<233<<endl;
	For(i,1,m){
		sort(all(vec[i]));
		ans=max(ans,(int)(vec[i].size()));
		For(j,0,vec[i].size()-1){
			int p=lower_bound(all(vec[i-1]),vec[i][j])-vec[i-1].begin();
			ans=max(ans,(int)(vec[i].size())-j+p);
		}
	}
	//cerr<<233<<endl;
	For(i,1,m-1){
		pr[i+1]=lower_bound(all(vec[i]),vec[i+1][0])-vec[i].begin();
		su[i]=vec[i+1].size()-(lower_bound(all(vec[i+1]),vec[i].back())-vec[i+1].begin());
	}
	pr[1]=su[m]=0;
	//cerr<<ans<<endl;
	int now=vec[1].size();
	ans=max(ans,now+su[1]);
	For(i,2,m){
		if (vec[i-1].back()<vec[i][0])
			now+=vec[i].size();
		else now=vec[i].size()+pr[i];
		ans=max(ans,now+su[i]);
	}
	cout<<n-ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}