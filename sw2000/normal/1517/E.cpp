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
typedef pair<ll, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod=998244353;

int n;
ll arr[N],pre[N];
ll solve(){
    cin>>n;
    ll sum=0,cnt=0;
    vector<pii>v[2];
    v[0].push_back({-linf,-inf});
    v[1].push_back({-linf,-inf});
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
        pre[i]=arr[i];
        if(i>=2)pre[i]+=pre[i-2];
        v[i%2].push_back({pre[i],i});
    }
    v[0].push_back({linf,inf});
    v[1].push_back({linf,inf});
    if(n==1)return 1;
    else if(n==2){
        if(arr[1]==arr[2])return 1;
        else return 2;
    }
    sum=(sum-1)/2;
    ll ret=1;
    for(int i=n;i>2;i--){
        cnt+=arr[i];
        if(cnt<=sum)ret++;
    }

    if(arr[1]<=sum){
        cnt=0;

        for(int i=1;i<=n;i++){
            cnt+=arr[i];
            if(sum-cnt<0)break;

            pii p=*(--lower_bound(v[i%2].begin(),v[i%2].end(),(pii){sum+pre[i]-cnt,inf}));
            ret+=(p.se-i)/2+1;

            p=*(--lower_bound(v[i%2].begin(),v[i%2].end(),(pii){sum+pre[i]-cnt-arr[n],inf}));
            while(n-p.se<=2)p.se-=2;
            if(p.se>=i)ret+=(p.se-i)/2+1;

            ret%=mod;
        }
    }
    if(arr[2]<=sum){
        sum+=arr[1];
        cnt=arr[1];

        for(int i=2;i<=n;i++){
            cnt+=arr[i];
            if(sum-cnt<0)break;

            pii p=*(--lower_bound(v[i%2].begin(),v[i%2].end(),(pii){sum+pre[i]-cnt,inf}));
            ret+=(p.se-i)/2+1;

            p=*(--lower_bound(v[i%2].begin(),v[i%2].end(),(pii){sum+pre[i]-cnt-arr[n],inf}));
            while(n-p.se<=2)p.se-=2;
            if(p.se>=i)ret+=(p.se-i)/2+1;

            ret%=mod;
        }
    }
    return ret%mod;
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