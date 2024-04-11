#include<bits/stdc++.h>
#define fi first
#define se second
//#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int n;ll s;cin>>n>>s;
    vi v(n);
    for(auto &i:v)cin>>i;
    sort(v.begin(),v.end());
    ll ss=0;
    int mi=1e9;
    for(auto i:v){
        ss+=i;
        mi=min(mi,i);
    }
    if(ss<s){
        cout<<-1;
        return 0;
    }
    int l=0,r=1e9;
    while(l<r){
        ll sum=0;
        int mid=(l+r+1)/2;
        for(auto i:v)sum+=max(0,i-mid);
        if(sum>=s)l=mid;
        else r=mid-1;
    }
    cout<<min(mi,l)<<endl;
	return 0;
}