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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,p;
    string s;
    //ll ans = 0;
     scanf("%d %d", &n, &p);
    double ans = 0;
    vd prob(n);
    forn(i,0,n) {
        int l,r;
        scanf("%d %d", &l, &r);
        int num = (r/p)-(l-1)/p;
        prob[i] = (double)num/(double)(r-l+1);
    }
    forn(i,0,n) {
        int l = i-1;
        if(l==-1) l=n-1;
        int r= (i+1)%n;
        ans+=2000.*prob[i];
        ans+=1000.*(1-prob[i])*(prob[l]);
        ans+=1000.*(1-prob[i])*(prob[r]);
    }
    printf("%.10lf", ans);
}