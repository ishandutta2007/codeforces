#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int two=0,four=0;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        if (cnt[a]%2==1) two++;
        if (cnt[a]%4==3) four++;
        cnt[a]++;
    }
    int q; cin >> q;
    char op; int a;
    for (int i=1;i<=q;++i){
        cin >> op >> a;
        if (op=='+'){
            if (cnt[a]%2==1) two++;
            if (cnt[a]%4==3) four++;
            cnt[a]++;
        }
        if (op=='-'){
            if (cnt[a]%2==0) two--;
            if (cnt[a]%4==0) four--;
            cnt[a]--;
        }
        cout << ((four>=1&&two>=4)?"YES":"NO") << '\n';
    }
}