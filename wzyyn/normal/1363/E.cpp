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
const int N=200005;
int n,a[N],b[N],c[N];
vector<int> e[N];
ll ans;
int dfs(int x,int fa,int v){
	v=min(v,a[x]);
	int key=0;
	key+=(b[x]?1:-1);
	key-=(c[x]?1:-1);
	key/=2;
	//cout<<x<<' '<<v<<' '<<key<<endl;
	for (auto i:e[x]) if (i!=fa){
		int val=dfs(i,x,v);
		if ((val>0)^(key>0))
			ans+=1ll*v*min(abs(val),abs(key));
		key+=val;
	}
	return key;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	if (dfs(1,0,1<<30))
		return puts("-1"),0;
	cout<<2*ans<<endl;
}