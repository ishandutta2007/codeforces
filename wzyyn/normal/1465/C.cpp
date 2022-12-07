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

const int N=100005;
int n,m,fa[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) fa[i]=i;
	int ans=m;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==y) ans--;
		else if (get(x)==get(y)) ans++;
		else fa[get(x)]=get(y);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}