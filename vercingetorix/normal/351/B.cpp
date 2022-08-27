#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n, x, w;
    cin >> n;
    vi p(n);
    for(int i=0; i<n; i++) cin>>p[i];
    int inv=0;
    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if (p[j] < p[i]) inv++;
    ll aans = 0;
    while (inv>1) {
        inv-=2;
        aans+=4;
    }
    double ans = aans;
    if(inv==0) printf("%.6f", ans);
    else if(inv==1) printf("%.6f", ans+1);
    

}