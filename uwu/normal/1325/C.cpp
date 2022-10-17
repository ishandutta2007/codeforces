#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

vector<int> graph[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int uwu=-1;
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        graph[a].push_back(i);
        graph[b].push_back(i);
        if (graph[a].size()>=3){
            uwu=a;
        }
        if (graph[b].size()>=3){
            uwu=b;
        }
    }
    if (uwu==-1){
        for (int i=0;i<=n-2;++i){
            cout << i << '\n';
        }
    }
    else{
        set<int> s;
        for (int i=0;i<=2;++i){
            s.insert(graph[uwu][i]);
        }
        int cnt=0,curr=3;
        for (int i=0;i<=n-2;++i){
            if (s.count(i)){
                cout << cnt++ << '\n';
            }
            else{
                cout << curr++ << '\n';
            }
        }
    }
}