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

const int N=200005;
vector<pii> op;
int n,a[N],vis[N],fl[N];
vector<int> v,v2;
void work(int x,int y){
	op.PB(pii(x,y));
	swap(a[x],a[y]);
	swap(fl[x],fl[y]);
	fl[x]^=1; fl[y]^=1;
}
void Merge2(vector<int> v1,vector<int> v2){
	work(v1[0],v2[0]);
	for (;a[v1[0]]!=v2[0];work(v1[0],a[v1[0]]));
	for (;a[v2[0]]!=v2[0];work(v2[0],a[v2[0]]));
}
void solve(int x){
	v2.resize(0);
	for (;!vis[x];v2.PB(x),vis[x]=1,x=a[x]);
	if (v.size()) Merge2(v,v2),v.resize(0);
	else v=v2;
}
void Merge1(vector<int> v){
	work(v[0],v[2]);
	work(v[0],v[1]);
	for (;a[v[2]]!=v[2];work(v[2],a[v[2]]));
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) if (a[i]!=i&&!vis[i]) solve(i);
	if (v.size()){
		if (v.size()!=n){
			For(i,1,n) if (a[i]==i){
				Merge2(v,vector<int>{i});
				break;
			}
		}
		else
			Merge1(v);
	}
	For(i,1,n) assert(a[i]==i&&!fl[i]);
	printf("%d\n",op.size());
	for (auto i:op) printf("%d %d\n",i.fi,i.se);
}
/*
2 3 4 1 6 7 8 5

*/