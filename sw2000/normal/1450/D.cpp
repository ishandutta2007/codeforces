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
bool ans[N];
int arr[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)ans[i]=0;
	unordered_map<int,int>mp;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}
	if(mp.size()==n){
		ans[1]=1;
	}
	for(int i=1,l=1,r=n;i<=n;i++){
		if(arr[l]==i){
			mp[i]--;
			l++;
		}else if(arr[r]==i){
			mp[i]--;
			r--;
		}else{
			if(mp[i])ans[n+1-i]=1;
			break;
		}
		ans[n+1-i]=1;
		if(mp[i])break;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
	cout<<endl;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("in.txt","r",stdin);
	int _;cin>>_;
	while(_--)solve();
	return 0;
}