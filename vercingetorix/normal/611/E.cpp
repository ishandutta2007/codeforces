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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    int a,b,c;
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);
    if(b<c) swap(b,c);
    if(a<b) swap(a,b);
    if(b<c) swap(b,c);
    vi t(n);
    forn(i,0,n) {
        scanf("%d", &t[i]);
    }
    int ans = 0;
    sort(all(t));
    reverse(all(t));
    int af = 0;
    int bf = 0;
    int bcf = 0;
    int cf = 0;
    int pt = 0;
    while(pt < t.size()) {
        if(t[pt] > a+b+c) {
            cout<<-1;
            return 0;
        }
        else if(t[pt] > a+b) {
            ans++;
            pt++;
            continue;
        }
        else if(t[pt] > a+c) {
            ans++;
            pt++;
            cf++;
            continue;
        }
        else if(t[pt] > b+c) {
            if(t[pt] <= a) {
                ans++;
                pt++;
                bcf++;
                continue;
            }
            else {
                ans++;
                pt++;
                bf++;
                continue;
            }
        }
        else break;
    }
    int nc = 0, nb = 0, nbc = 0, nvar = 0;
    forn(i,pt,t.size()) {
        if(t[i] <= c) nc++;
        else if(t[i]<=b) nb++;
        else {
            if(t[i]<=a) nvar++;
            else nbc++;
        }
    }
    while(nb>0 && bf>0) {
        nb--; bf--;
    }
    while(nc>0 && cf>0) {
        nc--; cf--;
    }
    while(nbc>0 && bcf>0) {
        nbc--; bcf--;
    }
    while(nbc>0) {
        ans++;
        af++;
        nbc--;
    }
    while(nvar>0 && af>0) {
        nvar--;
        af--;
    }
    while(cf>0 && nc >0) {
        cf--;
        nc--;
    }
    while(nvar>bcf) {
        ans++;
        nvar--;
        bcf++;
    }
    while(1) {
        int naf = af;
        int nbcf= bcf;
        int nbf=bf;
        int ncf=cf;
        int nnvar=nvar;
        int nnb=nb;
        int nnc=nc;
        while(nnvar>0) {
            if(naf>0) {
                int lol = min(naf,nnvar);
                naf-=lol;
                nnvar-=lol;
            }
            else if(nbcf>0) {
                int lol = min(nbcf,nnvar);
                nbcf-=lol;
                nnvar-=lol;
            }
            else break;
        }
        if(nnvar>0) {
            ans++;
            af++;
            bf++;
            cf++;
            continue;
        }
        nbf+=naf;
        nbf+=nbcf;
        ncf+=nbcf;
        if(nnb > nbf) {
            ans++;
            af++;
            bf++;
            cf++;
            continue;
        }
        ncf+=nbf-nnb;
        if(nnc>ncf) {
            ans++;
            af++;
            bf++;
            cf++;
            continue;
        }
        else {
            cout<<ans;
            return 0;
        }
    }
    
}