#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

#define X first
#define Y second

const int N=1e5+10;
const int maxv=1e6+10;
const string wowel="aeiou";


deque <int> v[2];
ii a[N];
int n,n1,h[maxv];
string s[N];
set <int> des[2];


string mto_string(int val){
    string ans;
    while (val) ans.push_back('0'+val%10),val/=10;
    reverse(ans.begin(),ans.end());
    return ans;
}
int convert(string s){
    for(int i=0;i<s.length();i++) if (s[i]<'0'||s[i]>'9') return -1;
    if (s[0]=='0') return -1;

    ///
    int ans=0;
    for(auto ch:s) ans=10*ans+ch-'0';
    return ans;
}
void prepare(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>a[i].Y;
        n1+=a[i].Y;
        a[i].X=convert(s[i]);
    }
}

void solve(){

    for(int i=1;i<=n1;i++) des[0].insert(i);
    for(int i=n1+1;i<=n;i++) des[1].insert(i);
    for(int i=1;i<=n;i++){
        if (a[i].Y==1){
            if (0<a[i].X&&a[i].X<=n1) des[0].erase(a[i].X);
            else {
                if (n1+1<=a[i].X&&a[i].X<=n) {
                    des[1].erase(a[i].X);
                    v[0].push_front(i);
                }else v[0].push_back(i);
            }
        }
        if (a[i].Y==0){
            if (n1+1<=a[i].X&&a[i].X<=n) des[1].erase(a[i].X);
            else {
                if (0<a[i].X&&a[i].X<=n1) {
                    des[0].erase(a[i].X);
                    v[1].push_front(i);
                }else v[1].push_back(i);
            }
        }
    }
    vector <pair<string,string>> ans;
    while (v[0].size()||v[1].size()){
        if (des[0].empty()&&des[1].empty()){
            int cur=v[0].back();
            string pos="999999";
            assert(n1+1<=a[cur].X&&a[cur].X<=n);
            des[1].insert(a[cur].X);
            ans.push_back(pair<string,string>(s[cur],pos));
            s[cur]=pos;
            a[cur].X=999999;
        }
        if (!des[0].empty()){
            int cur=v[0].front();
            v[0].pop_front();
            int num=*des[0].begin();
            ans.push_back(pair<string,string>(s[cur],mto_string(num)));
            des[0].erase(num);
            if (n1+1<=a[cur].X&&a[cur].X<=n) des[1].insert(a[cur].X);
            a[cur].X=num;
        }
        if (!des[1].empty()){
            int cur=v[1].front();
            v[1].pop_front();
            int num=*des[1].begin();
            ans.push_back(pair<string,string>(s[cur],mto_string(num)));
            des[1].erase(num);
            if (1<=a[cur].X&&a[cur].X<=n1) des[0].insert(a[cur].X);
            a[cur].X=num;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<"move "<<i.X<<" "<<i.Y<<'\n';
}
int main(){
    prepare();
    solve();
}