#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;

//int n,m,k,arr[N];
ll n;
int solve(){
    cin>>n;
    if(n%2050)return -1;
    n/=2050;
    int ret=0;
    while(n){
        ret+=n%10;
        n/=10;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
	return 0;
}