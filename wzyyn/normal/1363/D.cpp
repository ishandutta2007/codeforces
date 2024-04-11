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
#define double long double
using namespace std;
const int N=1005;
int n,k,ans[N];
vector<int> vec[N];
int q_full(){
	cout<<"? "<<n;
	For(i,1,n) cout<<' '<<i;
	cout<<endl;
	int x;
	cin>>x;
	assert(x!=-1);
	return x;
}
int q_range(int l,int r){
	int sum=0;
	For(i,l,r) sum+=vec[i].size();
	cout<<"? "<<sum;
	For(i,l,r) for (auto j:vec[i]) cout<<' '<<j;
	cout<<endl;
	int x;
	cin>>x;
	assert(x!=-1);
	return x;
}
int q_ban_range(int id){
	int sum=n-vec[id].size();
	static int vis[N];
	memset(vis,0,sizeof(vis));
	for (auto i:vec[id]) vis[i]=1;
	cout<<"? "<<sum;
	For(i,1,n) if (!vis[i]) cout<<' '<<i;
	cout<<endl;
	int x;
	cin>>x;
	assert(x!=-1);
	return x;
}
void solve(){
	cin>>n>>k;
	For(i,1,k){
		vec[i].resize(0);
		int x,y;
		cin>>x;
		for (;x--;){
			cin>>y;
			vec[i].PB(y);
		}
	}
	int val=q_full();
	int l=1,r=k;
	while (l<r){
		int mid=(l+r)/2;
		int v=q_range(l,mid);
		if (v==val){
			For(i,mid+1,r) ans[i]=val;
			r=mid;
		}
		else{
			For(i,l,mid) ans[i]=val;
			l=mid+1;
		}
	}
	ans[l]=q_ban_range(l);
	cout<<"!";
	For(i,1,k) cout<<' '<<ans[i];
	cout<<endl;
	string s;
	cin>>s;
	assert(s=="Correct");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}