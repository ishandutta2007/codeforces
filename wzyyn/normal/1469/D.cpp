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

int n,q[15];
vector<pii> op;
void solve(){
	scanf("%d",&n);
	op.resize(0);
	q[0]=2; q[1]=4; q[2]=16; q[3]=256; q[4]=65536; q[5]=n;
	int t=5;
	for (;q[t]<=q[t-1];q[t-1]=q[t],--t);
	Rep(i,t-1,0){
		For(j,q[i]+1,q[i+1]-1) op.PB(pii(j,j+1));
		op.PB(pii(q[i+1],q[i]));
		op.PB(pii(q[i+1],q[i]));
	}
	printf("%d\n",op.size());
	for (auto i:op) printf("%d %d\n",i.fi,i.se);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
4 16 256 n
*/