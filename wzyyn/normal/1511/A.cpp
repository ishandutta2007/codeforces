#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

int n,x;
void solve(){
	int S=0;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&x);
		S+=(x!=2);
	}
	cout<<S<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}