#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    vector<string> res;
    priority_queue<int,vi,greater<int> > heap;
    rep(i,0,n){
        string s;
        cin>>s;
        if(s=="insert"){
            cin>>k;
            heap.push(k);
            s+=" "+to_string(k);
        }
        if(s=="getMin"){
            cin>>k;
            while(heap.size() && heap.top()<k){
                heap.pop();
                res.pb("removeMin");
            }
            if(heap.empty() || heap.top()!=k){
                heap.push(k);
                res.pb("insert "+to_string(k));
            }
            s+=" "+to_string(k);
        }
        if(s=="removeMin"){
            if(heap.empty())
                res.pb("insert 1");
            else
                heap.pop();
        }
        res.pb(s);
    }
    cout<<res.size()<<"\n";
    for(string s:res)cout<<s<<'\n';
    return 0;
}