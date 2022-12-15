//By TheOneYouWant

#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;

const int LIM=1e6+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    
    int n;
    cin>>n;
    ll vowels[LIM][5];
    ll total[LIM] = {0};
    forn(i,LIM){
        forn(j,5) vowels[i][j] = 0;
    }
    vector<string> stores[LIM][5];

    forn(i,n){
        string s;
        cin>>s;
        int v = 0;
        char last;
        forn(i,s.length()){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                v++;
                last = s[i];
            }
        }
        total[v]++;
        int idlast = 0;
        if(last == 'a') idlast = 0;
        else if(last == 'e') idlast = 1;
        else if(last == 'i') idlast = 2;
        else if(last == 'o') idlast = 3;
        else if(last == 'u') idlast = 4;
        vowels[v][idlast] ++;
        stores[v][idlast].pb(s);
    }
    // cout<<"OK"<<endl;

    vector <string> answer1[2], answer2[2];

    forn(i,LIM){
        if(total[i] <2) continue;
        stack<string> s;
        forn(j,5){
            for(int t = 1; t < vowels[i][j]; t += 2){
                answer2[0].pb(stores[i][j][t]);
                answer2[1].pb(stores[i][j][t-1]);
            }
            if(vowels[i][j]%2 == 1){
                if(s.size()==0){
                    s.push(stores[i][j][vowels[i][j]-1]);
                }
                else{
                    string k = s.top();
                    s.pop();
                    answer1[0].pb(stores[i][j][vowels[i][j]-1]);
                    answer1[1].pb(k);
                }
            }
        }
    }
    // cout<<"OK"<<endl;

    ll ans = 0;
    if(answer1[0].size()>answer2[0].size()) ans = answer2[0].size();
    else ans = answer1[0].size() + ((answer2[0].size()-answer1[0].size())/2);

    cout<<ans<<ln;

    if(answer1[0].size()>answer2[0].size()){
        forn(i,answer2[0].size()){
            cout<<answer1[0][i]<<" "<<answer2[0][i]<<ln;
            cout<<answer1[1][i]<<" "<<answer2[1][i]<<ln;
        }
    }
    else{
        forn(i,answer1[0].size()){
            cout<<answer1[0][i]<<" "<<answer2[0][i]<<ln;
            cout<<answer1[1][i]<<" "<<answer2[1][i]<<ln;
        }
        // int l = answer1[0].size();
        for(int l = answer1[0].size()+1; l < answer2[0].size(); l+= 2){
            cout<<answer2[0][l-1]<<" "<<answer2[0][l]<<ln;
            cout<<answer2[1][l-1]<<" "<<answer2[1][l]<<ln;
        }
    }

    return 0;
}