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
    int n,s;cin>>n>>s;
    cout<<(s-1)/n+1;
    return 0;
}