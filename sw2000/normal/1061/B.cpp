#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod=220000607;
const int N=6e5+10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int n,m;cin>>n>>m;
    vi arr(n);
    ll sum=0;
    for(auto &i:arr){
        cin>>i;
        sum+=i;
    }
    sort(arr.begin(),arr.end());
    int ma=0;
    for(auto i:arr){
        ma=min(ma+1,i);
    }
    cout<<sum-(arr.back()-ma)-n<<endl;
    return 0;
}