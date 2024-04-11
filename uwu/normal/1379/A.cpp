#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=51;

char arr[51];
string uwu="abacaba";

bool check(int pos){
    for (int i=0;i<7;++i){
        if (!(arr[pos+i]==uwu[i]||arr[pos+i]=='?')) return false;
    }
    return true;
}

bool equals(int pos){
    for (int i=0;i<7;++i){
        if (!(arr[i+pos]==uwu[i])) return false;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> arr[i];
        bool flag=0;
        for (int i=1;i+6<=n;++i){
            if (!check(i)) continue;
            string temp="";
            for (int j=0;j<7;++j) temp+=arr[j+i], arr[j+i]=uwu[j];
            int cnt=0;
            for (int i=1;i+6<=n;++i){
                cnt+=equals(i);
            }
            if (cnt==1){ flag=1; break; }
            for (int j=0;j<7;++j) arr[j+i]=temp[j];
        }
        if (flag){
            cout << "yes" << '\n';
            for (int i=1;i<=n;++i){
                if (arr[i]=='?') cout << "z";
                else cout << arr[i];
            }
            cout << '\n';
        }
        else{
            cout << "no" << '\n';
        }
    }
}