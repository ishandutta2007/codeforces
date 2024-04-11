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
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;
#define M_PI 3.14159265358979323846

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

double pow(double k, int n) {
    if (n==0) return 1;
    if(n==1) return k;
    double x = pow(k, n/2);
    return x*x*pow(k, n%2);
}

long long cnk(ll n, ll k) {
    ll ans = 1;
    for(int i =0; i < k; i++) {
        if (ans%(i+1) == 0) ans = ((ans)/(i+1)) * (n-i);
        else if ((n-i)%(i+1) == 0) ans = ((n-i)/(i+1)) * (ans);
        else ans = ((ans)*(n-i)) / (i+1);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n;
    double r;
    cin>>n>>r;
    ll k= n/2;
    double horda = 2*r*sin(M_PI*k/(2*k+1));
    double horda1 = 2*r*sin(M_PI/(2*k+1));
    double hordak1 = 2*r*sin(M_PI*(k-1)/(2*k+1));
    double r1 = horda1 * sin(M_PI*(k-1)/(2*k+1));
    double r2 = hordak1 * sin(M_PI*(2)/(2*k+1));
    double side = horda * r1 / (r1+r2);
    double cross = 2*side * sin(M_PI/(4*k+2));
    printf("%.10lf", (2*k+1)*cross*r/2);

    
    //cout<<ans;
}