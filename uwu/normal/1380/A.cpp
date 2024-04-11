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
        bool flag=false; int temp1, temp2;
        for (int i=2;i<n;++i){
            temp1=temp2=0;
            for (int j=i-1;j>=1;--j) if (arr[j]<arr[i]) temp1=j;
            for (int j=i+1;j<=n;++j) if (arr[j]<arr[i]) temp2=j;
            if (temp1!=0&&temp2!=0){
                cout << "YES" << '\n';
                cout << temp1 << " " << i << " " << temp2 << '\n';
                flag=true;
                break;
            }
        }
        if (!flag) cout << "NO" << '\n';
    }
}