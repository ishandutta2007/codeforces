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

vector<int> cnt(10,0);
pii calc(const string& s,const string& t){
    int a=0, b=0;
    fill(allof(cnt),0);
    rep(i,0,4) cnt[s[i]-'0'] ++;
    rep(i,0,4) if(s[i]==t[i]) a++;
    rep(i,0,4) if(cnt[t[i]-'0']) b++, cnt[t[i]-'0']=0;
    return pii{a,b-a};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> pos;
    rep(a,0,10) rep(b,a+1,10) rep(c,b+1,10) rep(d,c+1,10){
        string s;
        s += a+'0';
        s += b+'0';
        s += c+'0';
        s += d+'0';
        do{
            pos.pb(s); 
        } while(next_permutation(allof(s)));
    }
    while(true){
        string s = "";
        int st = 1e9;
        vector<int> c(25);
        for(const string& t:pos){
            int tt = 0;
            fill(allof(c),0);
            for(const string& r:pos){
                pii p = calc(r,t);
                tt = max(tt,c[p.X*5+p.Y]++);
            }
            if(tt<st) s = t,st = tt;
        }
        cout<<s<<endl;
        pii p;
        cin>>p.X>>p.Y;
        if(p.X==4) return 0;
        vector<string> n;
        for(string& t:pos){
            if(p==calc(t,s)) n.pb(t);
        }
        swap(pos,n);
    }
    return 0;
}