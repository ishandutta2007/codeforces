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
const int N=6e5+10;
int n;
ll ans,cnt[N]{1},k;
char a[N],b[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n>>k;
    cin>>a+1>>b+1;
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]*2;
        if(a[i]=='b')cnt[i]--;
        if(b[i]=='a')cnt[i]--;
        if(cnt[i]>=k){
            ans+=k*(n-i+1);
            break;
        }
        ans+=cnt[i];
    }
    cout<<ans;
	return 0;
}