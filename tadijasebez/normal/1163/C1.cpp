#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mt make_tuple
map<pair<int,int>,int> cnt;
set<tuple<int,int,int>> all;
const int N=1050;
int x[N],y[N];
bool ban[N][N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i %i",&x[i],&y[i]);
	int lns=n*(n-1)/2;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		int X=x[i]-x[j],Y=y[i]-y[j];
		if(X<0 || (X==0 && Y<0))X=-X,Y=-Y;
		int G=__gcd(abs(X),abs(Y));
		X/=G;Y/=G;
		int C=X*y[i]-Y*x[i];
		if(all.count(mt(X,Y,C)))ban[i][j]=1,lns--;
		else all.insert(mt(X,Y,C));
	}
	ll ans=(ll)lns*(lns-1)/2;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(!ban[i][j]){
		int X=x[i]-x[j],Y=y[i]-y[j];
		if(X<0 || (X==0 && Y<0))X=-X,Y=-Y;
		int G=__gcd(abs(X),abs(Y));
		X/=G;Y/=G;
		ans-=cnt[{X,Y}];
		cnt[{X,Y}]++;
	}
	printf("%lld\n",ans);
	return 0;
}