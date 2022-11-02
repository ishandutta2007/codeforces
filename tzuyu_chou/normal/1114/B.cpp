#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m,k;
pair<int,int>a[200001];
int b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=n; i>=n-m*k+1 ;i--){
		ans+=a[i].fi;
		b[a[i].se]=1;
	}
	cout << ans << endl;
	int cur=0;
	int rnd=0;
	for(int i=1; i<=n ;i++){
		cur+=b[i];
		if(cur==m){
			cout << i << ' ';
			rnd++;
			cur=0;
			if(rnd==k-1) break;
		}
	}
}