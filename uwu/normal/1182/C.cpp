#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

map<char,int> v;
map<int,string> m[5];
string extra[MAXN];
vector<pair<string,string>> one,two,ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    v['a']=0; v['e']=1; v['o']=2; v['i']=3; v['u']=4;
    int n; cin >> n;
    string uwu;
    for (int i=1;i<=n;++i){
        cin >> uwu;
        int curr=0; int last;
        for (char x:uwu){
            if (v.count(x)) curr++, last=v[x]; 
        }
        if (m[last].count(curr)){
            two.push_back({uwu,m[last][curr]});
            m[last].erase(curr);
        }
        else{
            m[last][curr]=uwu;
        }
    }
    for (int i=0;i<5;++i){
        for (auto x:m[i]){
            if (extra[x.first]!=""){
                one.push_back({extra[x.first],x.second});
                extra[x.first]="";
            }
            else{
                extra[x.first]=x.second;
            }
        }
    }
    while (1){
        if (two.empty()) break;
        pair<string,string> a,b;
        if (!one.empty()){
            a=one.back(); b=two.back();
            one.pop_back(); two.pop_back();
        }
        else{
            if (two.size()==1) break;
            a=two.back(); two.pop_back();
            b=two.back(); two.pop_back();
        }
        ans.push_back({a.first+" "+b.first,a.second+" "+b.second});
    }
    cout << ans.size() << '\n';
    for (auto x:ans){
        cout << x.first << '\n' << x.second << '\n';
    }

}