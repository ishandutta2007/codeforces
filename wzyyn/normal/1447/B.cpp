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
vector<int> v0,v1;
int n,m;
int F(vector<int> v,int sgn){
	int S=0;
	For(i,0,v.size()-1) S+=v[i];
	sort(v.begin(),v.end());
	if (sgn==1&&v.size()==0) return -(1<<29);
	if (sgn==1) S-=2*v[0];
	for (;;){
		if (sgn+1>=v.size()) break;
		if (v[sgn]+v[sgn+1]>=0) break;
		S-=2*(v[sgn]+v[sgn+1]);
		sgn+=2;
	}
	return S;
}
void solve(){
	v0.resize(0);
	v1.resize(0);
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m){
		int x;
		scanf("%d",&x);
		if ((i+j)&1) v0.PB(x);
		else v1.PB(x);
	}
	cout<<max(F(v0,0)+F(v1,0),F(v0,1)+F(v1,1))<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}