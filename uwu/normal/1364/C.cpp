#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int arr[MAXN],ans[MAXN];
bool seen[MAXN+5];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i], seen[arr[i]]=1;
    int val=-1;
    arr[0]=arr[1];
    for (int i=1;i<=n;++i){
        if (arr[i]!=arr[i-1]){
            ans[i]=arr[i-1];
        }
        else{
            if (val<=MAXN){
                val++;
                while (seen[val]) val++;
            }
            ans[i]=val;
        }
    }
    for (int i=1;i<=n;++i) cout << ans[i] << " ";
    cout << '\n';
}