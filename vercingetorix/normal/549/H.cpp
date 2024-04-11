#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

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
    double a,b,c,d;
    ll x,y,z,t;
    cin>>x>>y>>z>>t;
    if((x*t)==(y*z)) {
        double ans=0;
        printf("%.10lf",ans);
        return 0;
    }
    a=x; b=y; c=z; d=t;
    double ans=1999999999;
    for(int ia=-1; ia<=1; ia+=2) {
        for(int ib=-1; ib<=1; ib+=2) {
            for(int ic=-1; ic<=1; ic+=2) {
                for(int id=-1; id<=1; id+=2) {
                    double A = ia*id-ib*ic;
                    double B = d*ia + a*id - c*ib-b*ic;
                    double C = a*d-b*c;
                    if((ia*id)==(ib*ic)) {
                        if(abs(B)<0.5) continue;
                        double x1=C/B;
                        if(abs(x1)<ans) ans = abs(x1);
                        continue;
                    }
                    double D = (B*B - 4*A*C);
                    if(D<0) continue;
                    double x1 = (-B+sqrt(D))/(2*A);
                    double x2 = (-B-sqrt(D))/(2*A);
                    if(abs(x1)<ans) ans = abs(x1);
                    if(abs(x2)<ans) ans = abs(x2);
                }
            }
        }
    }
    ans = min(ans, max(abs(a), abs(b)));
    ans = min(ans, max(abs(d), abs(b)));
    ans = min(ans, max(abs(a), abs(c)));
    ans = min(ans, max(abs(c), abs(d)));
    printf("%.10lf",ans);
}