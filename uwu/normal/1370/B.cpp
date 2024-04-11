#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

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
        vector<int> arr(2*n+1);
        vector<int> odd,even;
        for (int i=1;i<=2*n;++i){
            cin >> arr[i];
            if (arr[i]%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        if (odd.size()%2==1){
            odd.pop_back();
            even.pop_back();
        }
        else{
            if (odd.size()>=2) odd.pop_back(), odd.pop_back();
            else even.pop_back(),even.pop_back();
        }
        while (!even.empty()){
            cout << even.back() << " ";
            even.pop_back();
            cout << even.back() << '\n';
            even.pop_back();
        }
        while (!odd.empty()){
            cout << odd.back() << " ";
            odd.pop_back();
            cout << odd.back() << '\n';
            odd.pop_back();
        }

    }
}