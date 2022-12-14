#include<bits/stdc++.h>
#define lo (o<<1)
#define ro (o<<1|1)
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const int mod = 220000607;
bool solve(){
    int n;string s;cin>>n>>s;
    bool vis[200]{};
    for(int i=0;i<n;i++){
        if(i&&s[i]!=s[i-1]){
            if(vis[s[i]])return 0;
        }
        vis[s[i]]=1;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)cout<<(solve()?"YES":"NO")<<endl;
	return 0;
}