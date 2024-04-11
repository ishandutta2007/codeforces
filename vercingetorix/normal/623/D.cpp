#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, m, k;
    cin>>n;
    double ans = n;
    double psuc = 1.;
    set<pair<double, int>> cur;
    vd palive(n, 1.);
    vd p(n);


    vd pcaught(n);
    for(int i=0; i<n; i++) {
        cin>>p[i];
        //p[i]=50.;
        p[i]/=100.;
        psuc*=p[i];
        pcaught[i]=p[i];
        cur.insert(mp(-(1-p[i]), i));
        //fr.pb(mp(p[i], i));
    }
    for (int i = 0; i<2000000; i++) {
        ans += (1-psuc);
        double a = cur.begin()->first;
        int k = cur.begin()->second;
        cur.erase(cur.begin());
        psuc *= (1 - a);
        pcaught[k] += (1 - pcaught[k]) * p[k];
        cur.insert(mp(-((1-pcaught[k])*p[k]/pcaught[k]), k));
    }
    printf("%.10lf", ans);

    
}