#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> val(n),arr(n);
        int cnt0=0,cnt1=0;
        for (int i=0;i<n;++i) cin >> val[i];
        for (int i=0;i<n;++i){
            cin >> arr[i];
            if (arr[i]==0) cnt0++;
            else cnt1++;
        }
        if (cnt0!=0&&cnt1!=0) cout << "yes" << '\n';
        else{
            vector<int> temp=val;
            sort(temp.begin(),temp.end());
            if (temp==val) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
    }
}