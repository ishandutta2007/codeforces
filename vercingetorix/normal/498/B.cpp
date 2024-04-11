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
    int n, T;
    cin>>n>>T;
    vector<double>  p(n);
    vi t(n);
    for(int i=0; i<n; i++) {
        int pp, tt;
        cin>>pp>>t[i];
        p[i]=((double) pp)/100.;
    }
    double ans=0;
    vector<double> dp(T+1,0.);
    dp[T]=1.;
    for(int i=0; i<n; i++) {
        vector<double> newdp(T+1,0.);
        double curp = 0.;
        for(int j=T; j>=0; j--) {
            newdp[j]=curp;
            curp*=1-p[i];
            curp+=dp[j]*p[i];
        }
        double cur1p=1;
        double totalp=0;
        for(int j= 1; j<=t[i];j++){
            totalp+=cur1p*p[i];
            cur1p*=(1-p[i]);
        }
        double lo=1-totalp;
        for(int j=0; j<=T-t[i]; j++) {
            newdp[j]-=cur1p*newdp[j+t[i]];
            newdp[j]+=lo*dp[j+t[i]];
        }
        dp=newdp;
        double totp=0;
        for(int j=T; j>=0; j--) {
            totp+=dp[j];
        }
        ans+=totp;
    }
    printf("%.10lf", ans);
}