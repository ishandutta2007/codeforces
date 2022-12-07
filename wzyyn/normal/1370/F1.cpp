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
const int N=1005;
int n,p,d,mxd,fa[N];
vector<int> e[N];
vector<int> vec[N];
void dfs(int x,int fa,int d){
	mxd=max(mxd,d);
	vec[d].PB(x);
	::fa[x]=fa;
	for (auto i:e[x])
		if (i!=fa) dfs(i,x,d+1);
}
void init(int x,int ban){
	mxd=0;
	For(i,1,n) fa[i]=0;
	For(i,0,n) vec[i].resize(0);
	dfs(x,ban,0);
}
void solve(){
	cin>>n;
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		cin>>x>>y;
		e[x].PB(y);
		e[y].PB(x);
	}
	cout<<"? "<<n;
	For(i,1,n) cout<<' '<<i;
	cout<<endl;
	cin>>p>>d; 
	if (d==0){
		cout<<"! "<<p<<' '<<p<<endl;
		exit(0);
	}
	init(p,-1);
	int v=(d+1)/2,p1,tmp;
	cout<<"? "<<vec[v].size();
	for (auto i:vec[v]) cout<<' '<<i;
	cout<<endl;
	cin>>p1>>tmp;
	assert(tmp==d);
	int l=v+1,r=mxd,key=v;
	while (l<=r){
		int mid=(l+r)/2,p2;
		//cout<<"JUD "<<l<<' '<<r<<endl;
		cout<<"? "<<vec[mid].size();
		for (auto i:vec[mid]) cout<<' '<<i;
		cout<<endl;
		cin>>p2>>tmp;
		if (tmp==d)
			p1=p2,key=mid,l=mid+1;
		else r=mid-1;
	}
	int p2=p1;
	//cout<<"XIBA "<<p1<<' '<<key<<' '<<mxd<<endl;
	for (;fa[p2]!=p;p2=fa[p2]);
	init(p,p2);
	v=d-key;
	cout<<"? "<<vec[v].size();
	for (auto i:vec[v]) cout<<' '<<i;
	cout<<endl;
	cin>>p2>>tmp;
	cout<<"! "<<p1<<' '<<p2<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		solve();
		string jud;
		cin>>jud;
		if (jud!="Correct") break;
	}
}
/*
1
3
1 2
1 3
2 1
*/