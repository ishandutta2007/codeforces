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
        deque<int> q;
        for (int i=0,a;i<n;++i){
            cin >> a;
            q.push_back(a);
        }
        int ac=0,bc=0;
        int prev=0,curr=0;
        int cnt=0;
        while (!q.empty()){
            while (!q.empty()){
                curr+=q.front();
                ac+=q.front();
                q.pop_front();
                if (curr>prev||q.empty()){
                    cnt++;
                    break;
                }
            }
            prev=curr;
            curr=0;
            while (!q.empty()){
                curr+=q.back();
                bc+=q.back();
                q.pop_back();
                if (curr>prev||q.empty()){
                    cnt++;
                    break;
                }
            }
            prev=curr;
            curr=0;
        }
        cout << cnt << " " << ac << " " << bc << '\n';
    }
}