#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 10;
const ll mod = 1e9 + 7;

int arr[N];
int solve(){
	vi v;
	int n;cin>>n;
	unordered_map<int,int>mp;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
		ma=max(ma,mp[arr[i]]);
	}
	if(ma>(n+1)/2)return -1;
	for(int i=1,l=1;i<=n;i++){
		if(arr[i]==arr[i+1]||i==n){
			v.push_back(arr[l]);
			v.push_back(arr[i]);
			l=i+1;
		}
	}
	int ret=v.size()/2-1;
	
	mp.clear();
	ma=0;
	for(int i:v){
		mp[i]++;
		ma=max(ma,mp[i]);
	}
	int m=v.size()-2;
	ma-=2;
	if(ma<=m/2)return ret;
	else return ret+ma-m/2;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("in.txt","r",stdin);
	int _;cin>>_;
	while(_--)cout<<solve()<<endl;
	return 0;
}