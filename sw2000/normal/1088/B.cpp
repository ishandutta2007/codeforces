#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int n,k;cin>>n>>k;
    vi v(n);
    for(auto &i:v)cin>>i;
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=v.size()-1;i;i--){
        v[i]-=v[i-1];
    }
    if(v.size()<=k){
        for(auto i:v)cout<<i<<endl;
        for(int i=0;i<k-v.size();i++)cout<<0<<endl;
    }
    else for(int i=0;i<k;i++)cout<<v[i]<<endl;
	return 0;
}