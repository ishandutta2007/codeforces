#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

bool zero[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s; cin >> s; s=" "+s;
        int x,n; cin >> x; n=s.size()-1;
        for (int i=0;i<=n;++i) zero[i]=0;
        zero[0]=1;
        for (int i=1;i<=n;++i){
            if (s[i]=='0'){
                if (i>x) zero[i-x]=1;
                if (i+x<=n) zero[i+x]=1;
            }
        }
        bool flag=1;
        for (int i=1,idx1,idx2;i<=n;++i){
            if (s[i]=='0') continue;
            if (i>x) idx1=i-x;
            else idx1=0;
            if (i+x<=n) idx2=i+x;
            else idx2=0;
            if (zero[idx1]&&zero[idx2]) flag=0;
        }
        if (!flag) cout << -1 << '\n';
        else{
            for (int i=1;i<=n;++i) cout << (!zero[i]);
            cout << '\n';
        }
    }
}