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
int n,m,a[N];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	int p=n;
	for (;p&&a[p]==p;--p);
	double prob=(p==0?1:0);
	For(i,1,m){
		int x;
		double pp;
		scanf("%d%lf",&x,&pp);
		if (x>=p) prob+=(1-prob)*pp;
	}
	printf("%.10lf\n",prob);
	//cout<<prob<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}