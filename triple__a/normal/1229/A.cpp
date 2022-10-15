#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
using namespace std;
 
const int maxn=7007;
int n;
struct arr{
	long long a,b;
	friend bool operator<(arr x,arr y){
		return x.a<y.a;
	}
}e[maxn];
long long ans=0;
bool vis[maxn];
vector<pair<long long,long long> > vec; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	rep(i,n) cin>>e[i].a;
	rep(i,n) cin>>e[i].b;
	sort(e,e+n);
	long long u=0;
	rep(i,n){
		if ((i>0&&e[i].a==e[i-1].a)||(i<n-1&&e[i].a==e[i+1].a)){
			vis[i]=1;
			vec.push_back({e[i].a,e[i].b});
		}
	}
	rep(i,n){
		for (auto c:vec){
			if ((e[i].a|c.first)==c.first){
				ans+=e[i].b;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}