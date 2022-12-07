#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int p1=1,p2=1,p3=1;
	For(i,1,a-1) p1*=10;
	For(i,1,b-1) p2*=10;
	For(i,1,c-1) p3*=10;
	cout<<p1+p3<<' '<<p2<<endl;
}
int main(){
	int T;
	scanf("%d",&T); 
	while (T--) solve();
}