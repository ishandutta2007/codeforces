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
    ll n,m;
    int ans = 0;
    cin>>n;
    vi a(n), b(n), gend(n);
    for(int i=0; i<n; i++) {
        char c;
        cin >> c >>a[i]>>b[i];
        if(c=='F') gend[i] =0;
        else gend[i]=1;
    }
    for(int day=1; day<=366; day++) {
        int f=0, m=0;
        for(int i=0; i<n; i++) {
            if((a[i]<=day)&&(day<=b[i])) {
                if(gend[i]==0) f++;
                else m++;
            }
        }
        ans=max(ans, min(f,m));
    }
    
    
    cout<<2*ans;
}