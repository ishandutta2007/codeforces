#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vvi deps;
vi decent(400, 1);;
vector < vector<int> > g; // 
int npi;

vector<char> used;
int startv;
void dfs (int v) {
    if(abs(v-startv)==200) decent[startv]=0;
    used[v] = true;
    deps[startv].pb(v);
    for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
        if (!used[*i])
            dfs (*i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    g.resize(400);
    deps.resize(400);
    int n,a,b;
    string ans;
    string sson;
    cin>>sson;
    int l = sson.size();
    vi son(l);
    forn(i,0,l) son[i] = (sson[i]=='V')? 0 : 1;
    bool csuck=false, vsuck=false;
    int m;
    cin>>n>>m;
    forn(i,0,m) {
        int p1,p2;
        char t1,t2;
        cin>>p1>>t1>>p2>>t2;
        if(t1=='V') if(t2=='C') vsuck=true;
        if(t1=='C') if(t2=='V') csuck=true;
        p1--;
        p2--;
        int tt1 = (t1=='V') ? 0 : 1;
        int tt2 = (t2=='V') ? 0 : 1;
        g[p1+tt1*200].pb(p2+tt2*200);
        g[p2+(1-tt2)*200].pb(p1+(1-tt1)*200);
    }
    string s;
    cin>>s;
    
    bool vpr=false, cpr=false;
    int minv=301, minc=1489;
    forn(i,0,l) {
        if(son[i]) {cpr=true; minc=min(minc,i);}
        else {vpr=true; minv=min(minv,i);}
    }
    if(!cpr) {
        if(vsuck) cout<<-1;
        else cout<<s;
        return 0;
    }
    if(!vpr) {
        if(csuck) cout<<-1;
        else cout<<s;
        return 0;
    }
    vi src(n);
    forn(i,0,n) {
        src[i] = son[s[i]-'a'];
    }
    forn(i,0,n) {
        startv = i;
        used.clear();
        used =move(vector<char>(400,false));
        dfs(i);
        startv = i+200;
        used.clear();
        used =move(vector<char>(400,false));
        dfs(i+200);
    }
    bool f = true;
    for(int fc = 0; fc<=n; fc++) {
        string cand;
        vi vow(n, -1);
        forn(i, 0, fc) vow[i] = src[i];
        forn(i, 0, fc) cand.pb(s[i]);
        forn(i, 0, fc) {
            for(auto x : deps[i+200*src[i]]) {
                if(x<200) {
                    if(vow[x]==1) {
                        f=false;
                        break;
                    }
                    vow[x]=0;
                }
                else {
                    if(vow[x-200]==0) {
                        f=false;
                        break;
                    }
                    vow[x-200]=1;
                }
            }
            if(!f) break;
        }
        if(!f) break;
        if(fc==n) {
            ans =cand;
            break;
        }
        int cursym = s[fc] - 'a';
        if (cursym == l-1) continue;
        int nx = cursym+1;
        int curr =  cursym+2;
        int ny = -1;
        while(curr<l) {
            if(son[curr] != son[nx]) {
                ny=curr;
                break;
            }
            curr++;
        }
        if(ny>=0) {
            // test sym to ny
            vi vow2 = vow;
            string candy = {(char)('a'+ny)};
            bool fy = true;
            for(auto x : deps[fc + 200*son[ny]]) {
                if(x<200) {
                    if(vow2[x]==1) {
                        fy=false;
                        break;
                    }
                    vow2[x]=0;
                }
                else {
                    if(vow2[x-200]==0) {
                        fy=false;
                        break;
                    }
                    vow2[x-200]=1;
                }
            }
            forn(i,fc+1,n) {
                if(vow2[i]<0) {
                    if(decent[i+200*son[0]]) {
                        vow2[i] = son[0];
                        
                    }
                    else {
                        vow2[i] = 1-son[0];
                        
                    }
                }
                if(vow2[i]==son[0]) candy.pb('a');
                else candy.pb((char)'a' + max(minv,minc));
                for(auto x : deps[i+200*vow2[i]]) {
                    if(x<200) {
                        if(vow2[x]==1) {
                            fy=false;
                            break;
                        }
                        vow2[x]=0;
                    }
                    else {
                        if(vow2[x-200]==0) {
                            fy=false;
                            break;
                        }
                        vow2[x-200]=1;
                    }
                }
            }
            if(fy) ans = cand+candy;
        }
        // test sym to nx
        
        // test sym to ny
        bool fx=true;
        string candx = {(char)('a'+nx)};
        for(auto x : deps[fc + 200*son[nx]]) {
            if(x<200) {
                if(vow[x]==1) {
                    fx=false;
                    break;
                }
                vow[x]=0;
            }
            else {
                if(vow[x-200]==0) {
                    fx=false;
                    break;
                }
                vow[x-200]=1;
            }
        }
        forn(i,fc+1,n) {
            if(vow[i]<0) {
                if(decent[i+200*son[0]]) {
                    vow[i] = son[0];
                }
                else {
                    vow[i] = 1-son[0];
                }
            }
            if(vow[i]==son[0]) candx.pb('a');
            else candx.pb((char)'a' + max(minv,minc));
            for(auto x : deps[i+200*vow[i]]) {
                if(x<200) {
                    if(vow[x]==1) {
                        fx=false;
                        break;
                    }
                    vow[x]=0;
                }
                else {
                    if(vow[x-200]==0) {
                        fx=false;
                        break;
                    }
                    vow[x-200]=1;
                }
            }
        }
        if(fx) ans = cand+candx;
        
    }
    if(ans.size()==0) cout<<-1;
    else     cout<<ans;
}