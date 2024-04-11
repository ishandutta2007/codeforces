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

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

//vi cnt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    vi deg2(400000,0);
    int d2 = 1;
    while(d2<200000) {
        deg2[d2]=1;
        d2*=2;
    }
//    vi par(130000);
//    par[1] = 1;
//    par[2] = 1;
//    cnt.resize(n+1);
//    cnt[1] = 1;
//    cnt[2] = 2;
//    int level;
//    for(level = 2; level < n; level = level + 1){
//        cnt[level + 1] = cnt[level];
//        for(int position = cnt[level-1] + 1; position <= cnt[level]; position = position + 1){
//            if(deg2[position]){
//                par[cnt[level + 1] + 1] = position;
//                par[cnt[level + 1] + 2] = position;
//                cnt[level + 1] = cnt[level + 1] + 2;
//            }else{
//                par[cnt[level + 1] + 1] = position;
//                cnt[level + 1] = cnt[level + 1] + 1;
//            }
//        }
//    }
    vi par;
    par.pb(0);
    forn(i,1,200000) {
        par.pb(i);
        if(deg2[i]) par.pb(i);
    }
    vector<vpi> seg(n+10);
    vector<vi> val(n+10);
    vvi voi(n+1);
    vector<vvi> avoi(n+1);
    vvi query(m);
    forn(qq, 0, m) {
        int c;
        scanf("%d", &c);
                    query[qq].pb(c);
        if(c == 2) {
            int t,v;
            scanf("%d %d", &t, &v);
            query[qq].pb(t);
                        query[qq].pb(v);
            voi[t].pb(v);
            avoi[t].pb(vi());
        }
        else if (c == 1) {
            int t,l,r,x;
            scanf("%d %d %d %d", &t,&l,&r,&x);
                        query[qq].pb(t);
            query[qq].pb(l);
                        query[qq].pb(r);
            query[qq].pb(x);
        }
    }
    
    forn(qq, 0, m) {
        int c;
        c= query[qq][0];
        if(c == 2) {
//            vi ans;
            int t,v;
            //scanf("%d %d", &t, &v);
            t= query[qq][1];
            v=query[qq][2];
//            forn(i,0,seg[t].size()) {
//                if((v>=seg[t][i].first) && (v<=seg[t][i].second)) ans.pb(val[t][i]);
//            }
            int cur =0;
            while(voi[t][cur]!=v) cur++;
            vi & ans = avoi[t][cur];
            sort(all(ans));
            int ann = 0;
            for(int i = 0; i<ans.size(); i ++) {
                if (i==0) ann++;
                else if (ans[i]!=ans[i-1]) ann++;
            }
            printf("%d\n", ann);
        }
        else if (c == 1) {
            int t,l,r,x;
            //scanf("%d %d %d %d", &t,&l,&r,&x);
            t=query[qq][1];
            l=query[qq][2];
            r=query[qq][3];
            x=query[qq][4];
            for(int lev = t; lev >= 1; lev--) {
                for(int i = 0; i < voi[lev].size(); i++) {
                    if(voi[lev][i]>=l && voi[lev][i]<=r) avoi[lev][i].pb(x);
                }
                //seg[lev].pb(mp(l,r));
//                val[lev].pb(x);
                l=par[l];
                r=par[r];
            }
        }
    }
    
}