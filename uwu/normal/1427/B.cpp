#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        string s; cin >> s; s="L"+s+"L";
        int tot=0;
        for (int i=1;i<=n;++i){
            if (s[i]=='W') tot+=1+(s[i-1]=='W');
        }
        vector<int> seg;
        int beg=0, end=n+1;
        for (int i=1;i<=n;++i){
            if (s[i]=='L') beg=i;
            else break;
        }
        if (beg==n){
            cout << max(0,2*k-1) << '\n';
            continue;
        }
        for (int i=n;i>=1;--i){
            if (s[i]=='L') end=i;
            else break;
        }
        int cnt=0;
        for (int i=beg+1;i<end;++i){
            if (s[i]=='L') cnt++;
            else{
                if (cnt==0) continue;
                seg.push_back(cnt);
                cnt=0;
            }
        }
        sort(seg.begin(),seg.end());
        for (int x:seg){
            if (k>=x) tot+=2*x+1, k-=x;
            else tot+=2*k, k=0;
        }
        end=n-end+1;
        end=min(end+beg,k);
        tot+=end*2, k-=end;
        cout << tot << '\n';
    }
}