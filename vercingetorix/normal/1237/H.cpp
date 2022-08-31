#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vi s1,s2;

vi tos(string & x) {
    int n = x.size();
    vi ret;
    for(int i = 0; i<n; i+=2) {
        if(x[i]=='0' && x[i+1] == '0') ret.pb(0);
        if(x[i]=='1' && x[i+1] == '1') ret.pb(1);
        if(x[i]=='0' && x[i+1] == '1') ret.pb(2);
        if(x[i]=='1' && x[i+1] == '0') ret.pb(3);
    }
    return ret;
}

void rev(vi & a, int k) {
    forn(i,0,k/2) {
        swap(a[i], a[k-1-i]);
        if(a[i]>=2) a[i] = 5-a[i];
        if(a[k-1-i]>=2) a[k-1-i] = 5-a[k-1-i];
    }
    if(k%2==1) {
        if(a[k/2]>=2) a[k/2] = 5-a[k/2];
    }
}

void rem(vi & a, int pos) {
    forn(i,pos,int(a.size())-1) a[i] = a[i+1];
    a.pop_back();
}

void upd(vi & op, int pos) {
    forn(i,0,op.size()) {
        if(op[i] > pos) {
            pos = op[i]-1-pos;
            op[i]+=1;
        }
    }
}

void duatiga(vi & a) {
    forn(i,0,a.size()) if(a[i]>=2) a[i] = 5-a[i];
}
void zone(vi & a) {
    forn(i,0,a.size()) if(a[i]<=1) a[i] = 1-a[i];
}

vi go() {
    int n = s1.size();
    if(n==0) return vi();
    for(int i = n-1; i>=0; i--) if(s1[i] == s2.back()) {
        vi ret;
        ret.pb(i+1);
        ret.pb(n);
        rev(s1,i+1);
        rev(s1,n);
        s1.pop_back();
        s2.pop_back();
        for(auto x : go()) ret.pb(x);
        return ret;
    }
    for(int i = n-1; i>=0; i--) if(s2[i] == s1.back()) {
        rev(s2, i+1);
        rev(s2, n);
        s2.pop_back();
        s1.pop_back();
        vi ret = go();
        ret.pb(n);
        ret.pb(i+1);
        return ret;
    }
    if(s2.back() == 0 || s2.back() == 1) {
        int pt = 0;
        while(s1[pt] != s2.back()) pt++;
        vi ret;
        ret.pb(pt+1);
        ret.pb(n);
        rev(s1,pt+1);
        rev(s1,n);
        s1.pop_back();
        s2.pop_back();
        for(auto x : go()) ret.pb(x);
        return ret;
    }
    if (s1.back() == 0 || s1.back() == 1) {
        int pt = 0;
        while(s2[pt] != s1.back()) pt++;
        rev(s2, pt+1);
        rev(s2, n);
        s2.pop_back();
        s1.pop_back();
        vi ret = go();
        ret.pb(n);
        ret.pb(pt+1);
        return ret;
    }
    if(s1.back() == s2.back()) {
        s1.pop_back();
        s2.pop_back();
        return go();
    }
    if(s2.back() == 3) {
        duatiga(s1);
        duatiga(s2);
    }
    
    
    // s2.back() = 2
    vi ret;
    int p0=0,p1=0,p3=0;
    vi to;
    for(auto x : s1) {
        if(x==0) {
            while (s2[p0] != 0) p0++;
            to.pb(p0++);
        }
        else if(x==1) {
            while (s2[p1] != 1) p1++;
            to.pb(p1++);
        }
        else {
            while (s2[p3] != 2) p3++;
            to.pb(p3++);
        }
    }
    forn(i,0,n) {
        int add = n-1-i;
        forn(j,0,i) if(to[j] < to[i]) add++;
        ret.pb(add+1);
        if(add>0) ret.pb(add);
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    cin>>t;
    while(t--) {
        string a,b;
        cin>>a>>b;
        int n = a.size();
        s1 = tos(a);
        s2 = tos(b);
        vi cdiff(4,0);
        for(auto x : s1) cdiff[x] ++;
        for(auto x : s2) cdiff[x] --;
        if(cdiff[0] != 0 || cdiff[1] != 0) {
            printf("-1\n");
            continue;
        }
        vi ans = go();
        printf("%d\n", (int)ans.size());
        for(auto x : ans) printf("%d ", 2*x);
        printf("\n");
    }
}