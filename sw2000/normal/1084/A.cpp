#include<bits/stdc++.h>
#define fi first
#define se second
//#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int N=100+10;
int n,arr[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mi=inf;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[j]*4*max(j,i);
        }
        mi=min(mi,sum);
    }
    cout<<mi;
	return 0;
}