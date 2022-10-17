#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,res,a[200500],cur,d;
map<int,int> mp;
set<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		res=0;
		mp.clear();
		s.clear();
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			s.insert(a[i]);
			mp[a[i]]++;
		}
		for(auto [x,y]:mp){
			k=y;
			
			auto it=s.upper_bound(x);
			if(it==s.end()){
				res=max(res,k);
				continue;
			}
			d=(*it)-x;
			k++;
			
			while(1){
				if(d>1e9){
					break;
				}
				if((0ll+(ll)x+(ll)d+(ll)d)>1e9){
					break;
				}
				it=s.lower_bound(x+d+d);
				if(it==s.end())break;
				d=(*it)-x;
				k++;
			}
			res=max(res,k);
		}
		cout<<n-res<<'\n';
	}
}