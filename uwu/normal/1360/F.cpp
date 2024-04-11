#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Item{string s; int x;};

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        vector<string> arr(n);
        for (int i=0;i<n;++i) cin >> arr[i];
        queue<Item> q; q.push({"",0});
        string str; int curr,uwu;
        for (int idx=0;idx<m;++idx){
            int qsize=q.size();
            for (int _=0;_<qsize;++_){
                str=q.front().s; curr=q.front().x; q.pop();
                //cout << str << " " << curr << " | ";
                for (char c='a';c<='z';++c){
                    uwu=0;
                    for (int i=0;i<n;++i) if (arr[i][idx]!=c) uwu|=(1<<i);
                    if ((uwu&curr)==0) q.push({str+c,uwu|curr});
                }
            }
        }
        if (q.empty()) cout << -1 << '\n';
        else cout << q.front().s << '\n';
    }
}