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
    int n,m;
    string s;
    cin >> s;
    n=s.length();
    vb sw(n+1, false);
    int a;
    cin>>m;
    for(int i=0; i<m; i++) {
        cin>>a;
        sw[a-1]=!sw[a-1];
        sw[n-a+1]=!sw[n-a+1];
    }
    bool cur=true;
    for(int i=0; i<n; i++) {
        if(sw[i]) cur=!cur;
        if(cur) cout<<s[i];
        else cout<<s[n-i-1];
    }

    

}