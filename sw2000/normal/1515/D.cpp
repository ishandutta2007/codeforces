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

int n,l,r;
int solve(){
    cin>>n>>l>>r;
    map<int,int>ll,rr;
    for(int i=0;i<l;i++){
        int a;cin>>a;
        ll[a]++;
    }
    for(int i=0;i<r;i++){
        int a;cin>>a;
        rr[a]++;
    }
    for(auto &i:rr){
        int mi=min(i.se,ll[i.fi]);
        i.se-=mi;
        ll[i.fi]-=mi;
    }
    int ret=0;
    if(l>r){
        swap(ll,rr);
        swap(l,r);
    }

    for(auto i:rr){
        ret+=i.se/2;
    }
    int sum=0;
    for(auto i:ll)sum+=i.se;
    ret=sum+abs(l-r)-min(ret,abs(l-r)/2);
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
	return 0;
}