#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=15'000'001,L=3874;

int freq[MAXN];
bool sieve[L];
vector<int> p;

void gen_primes(){
    ms(sieve,1);
    sieve[0]=sieve[1]=0;
    for (int i=2;i<L;++i){
        if (!sieve[i]) continue;
        p.push_back(i);
        for (int k=i*i;k<L;k+=i) sieve[k]=0;
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    gen_primes();
    vector<int> arr(n+1);
    cin >> arr[1];
    int uwu=arr[1];
    for (int i=2,a;i<=n;++i){
        cin >> a;
        arr[i]=a;
        uwu=__gcd(uwu,arr[i]);
    }
    for (int i=1,a;i<=n;++i){
        a=arr[i]/uwu;
        for (int x:p){
            if (x>a) break;
            if (a%x==0){
                freq[x]++;
                while (a%x==0) a/=x;
            }
        }
        freq[a]++;
    }
    int ans=n;
    for (int i=2;i<MAXN;++i){
        ans=min(ans,n-freq[i]);
    }
    if (ans==n) cout << -1 << '\n';
    else cout << ans << '\n';
}