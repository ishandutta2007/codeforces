#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
using namespace std;

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	int mn=max(k,n);
	mn+=mn%k; 
	cout<<mn/n+(mn%n!=0)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}