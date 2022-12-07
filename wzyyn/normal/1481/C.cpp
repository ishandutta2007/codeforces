#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=100005;
int n,m,re[N];
int a[N],b[N],c[N];
vector<int> v1[N];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,m) scanf("%d",&c[i]);
	int p=-1;
	For(i,1,n) if (c[m]==b[i])
		if (b[i]!=a[i]||p==-1) p=i;
	if (p==-1) return puts("NO"),void(0);
	re[m]=p;
	For(i,1,n)
		v1[i].resize(0);
	For(i,1,n) if (i!=p)
		if (a[i]!=b[i]) v1[b[i]].PB(i);
	For(i,1,m-1)
		if (v1[c[i]].size()){
			re[i]=v1[c[i]].back();
			v1[c[i]].pop_back();
		}
		else re[i]=p;
	//cout<<p<<endl;
	For(i,1,n)
		if (v1[i].size())
			return puts("NO"),void(0);
	puts("YES");
	For(i,1,m) printf("%d ",re[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}