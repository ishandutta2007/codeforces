#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;

bool solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a==1)return (n-1)%b==0;
    for(ll i=1;i<=n;i*=a){
        if((n-i)%b==0)return 1;
    }
    return 0;
}
int main() {
//    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        cout<<(solve()?"Yes":"No")<<'\n';
    }
}