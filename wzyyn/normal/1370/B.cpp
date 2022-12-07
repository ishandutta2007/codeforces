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
vector<int> v[2]; 
void mian(){
	v[0].resize(0);
	v[1].resize(0);
	int n,x;
	cin>>n;
	For(i,1,2*n){
		cin>>x;
		v[x&1].PB(i);
	}
	int rem=2;
	if (v[1].size()&1) v[1].pop_back(),--rem;
	for (;rem&&v[0].size();) v[0].pop_back(),--rem;
	for (;rem&&v[1].size();) v[1].pop_back(),--rem;
	For(i,0,v[0].size()-1) printf("%d%c",v[0][i],i&1?'\n':' ');
	For(i,0,v[1].size()-1) printf("%d%c",v[1][i],i&1?'\n':' ');
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}