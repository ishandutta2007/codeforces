#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        for (int i=1;i<=n;++i) cin >> arr[i];
        int pos1=n,pos2=n;
        for (int i=n;i>=1;--i){
            if (arr[i]>arr[i-1]||i==1){ pos1=i; break;}
        }
        for (int i=pos1;i>=1;--i){
            if (arr[i]<arr[i-1]||i==1){ pos2=i; break;}
        }
        cout << pos2-1 << '\n';
    }
}