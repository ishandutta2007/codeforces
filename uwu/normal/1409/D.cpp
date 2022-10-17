#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=20;

int arr[MAXN];
ll p10[19];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    p10[0]=1;
    for (int i=1;i<=18;++i) p10[i]=p10[i-1]*10;
    while (t--){
        string x; int s; cin >> x >> s;
        ms(arr,0);
        reverse(x.begin(),x.end());
        ll idx=0,tot=0,ans=0;
        for (char e:x){
            tot+=e-'0';
            arr[idx++]=e-'0';
        }
        if (tot<=s){ cout << 0 << '\n'; continue; }
        for (int i=0;i<x.size();++i){
            if (arr[i]==0) continue;
            ans+=p10[i]*(10-arr[i]); arr[i+1]++;
            tot+=1-arr[i]; arr[i]=0;
            if (tot<=s) break;
        }
        cout << ans << '\n';
    }
}