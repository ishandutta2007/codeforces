#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;

bool solve(){
    int n;cin>>n;
    int cnt=0;
    for(int i=0;i<n*2;i++){
        int a;cin>>a;
        cnt+=a%2;
    }
    return cnt==n;
}
int main() {
//    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        cout<<(solve()?"Yes":"No")<<'\n';
    }
}