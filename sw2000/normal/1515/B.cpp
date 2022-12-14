#include<bits/stdc++.h>
#define lo (o<<1)
#define ro (o<<1|1)
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 10;

int n,arr[N];
set<int>s;
void solve(){
    int n;cin>>n;
    if(n%2==0&&s.count(n/2)||n%4==0&&s.count(n/4)){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main(){
    for(int i=1;i*i<=1e9;i++)s.insert(i*i);
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
	return 0;
}