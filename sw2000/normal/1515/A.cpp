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
void solve(){
    int n,x;cin>>n>>x;
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==x){
            if(i==n-1){
                cout<<"NO";
                return;
            }
            swap(arr[i],arr[i+1]);
            break;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)cout<<arr[i]<<' ';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
        cout<<endl;
    }
	return 0;
}