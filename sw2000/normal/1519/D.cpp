#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4 + 10;

int n;
ll arr[N],brr[N],ans,ma;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<n*2;i+=2)cin>>arr[i];
    for(int i=1;i<n*2;i+=2){
        cin>>brr[i];
        ans+=arr[i]*brr[i];
    }
    for(int i=1;i<n*2;i++){
        ll add=0;
        for(int k=1;;k++){
            int l=i-k,r=i+k;
            if(l<1||r>=n*2)break;
            add+=(arr[r]-arr[l])*brr[l]+(arr[l]-arr[r])*brr[r];
            ma=max(ma,add);
        }
    }
    cout<<ans+ma;
    return 0;
}