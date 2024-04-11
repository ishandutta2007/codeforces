#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
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

struct aeb {
    aeb(double a, double b): a(a), b(b) {};
    long double a;
    long double b;
};

bool comp(aeb x, aeb y) {
    long double err = 0.000000000000001;
    if((x.a<=0)&&(y.a>0)) return true;
    if((y.a<=0)&&(x.a>=0)) return false;
    if((x.a<=0)&&(y.a<=0)) {
        x.a=-x.a;
        y.a=-y.a;
        return(comp(y,x));
    }
    long double v1 = log(x.a)+x.b;
    long double v2=log(y.a)+y.b;
    return(v1+err<v2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n,m,k;
    string s;
    //ll ans = 0;
    long double x,y,z;
    cin>>x>>y>>z;
    aeb curbest(-1, 9999999.);
    int i = -1;
    aeb cand= aeb(log(x),log(y)*z);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 0;
    }
    cand = aeb(log(x),log(z)*y);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 1;
    }
    cand = aeb(log(x)* y * z, 0);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 2;
    }
    
    cand = aeb(log(y),log(x)*z);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 4;
    }
    cand = aeb(log(y),log(z)*x);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 5;
    }
    cand = aeb(log(y)* x * z,0);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 6;
    }
    cand = aeb(log(z),log(x)*y);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 8;
    }
    cand = aeb(log(z),log(y)*x);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 9;
    }
    cand = aeb(log(z)* y * x,0);
    if(comp(curbest,cand)) {
        curbest = cand;
        i = 10;
    }
    vector<string> ans(12);
    ans[0]="x^y^z";
    ans[1]="x^z^y";
    ans[2]="(x^y)^z";
    ans[4]="y^x^z";
    ans[5]="y^z^x";
    ans[6]="(y^x)^z";
    ans[8]="z^x^y";
    ans[9]="z^y^x";
    ans[10]="(z^x)^y";
    cout<<ans[i];
}