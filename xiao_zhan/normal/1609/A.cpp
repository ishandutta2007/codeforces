#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t;
ll a[100500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll sb=1;
		for(i=1;i<=n;i++){
			cin>>a[i];
			while(!(a[i]&1)){
				sb<<=1;
				a[i]>>=1;
			}
		}
		sort(a+1,a+n+1);
		ll res=a[n]*sb;
		for(i=1;i<n;i++){
			res+=a[i];
		}
		cout<<res<<'\n';
	}
}