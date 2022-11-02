#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;cin >> n;
		for(int i=1; i<=n ;i++) cin >> a[i];
		int l=1,r=n;
		ll x=0,y=0,z=0;
		bool w=true;
		int rr=0;
		while(l<=r){
			rr++;
			w^=1;
			if(!w){
				ll s=0;
				while(l<=r && s<=z) s+=a[l++];
				z=s;
				x+=s;
			}
			else{
				ll s=0;
				while(l<=r && s<=z) s+=a[r--];
				z=s;
				y+=s;
			}
		}
		cout << rr << ' ' << x << ' ' << y << '\n';
	}
}