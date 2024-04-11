#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[8001];
ll p[8001];
ll c[8001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;cin >> n;
		for(int i=1; i<=n ;i++) c[i]=false;
		for(int i=1; i<=n ;i++){
			cin >> a[i];
			p[i]=p[i-1]+a[i];
			for(int j=0; j<i-1 ;j++){
				if(p[i]-p[j]<=n) c[p[i]-p[j]]=true;
			}
		}
		int ans=0;
		for(int i=1; i<=n ;i++){
			if(c[a[i]]) ans++;
		}
		cout << ans << '\n';
	}
}