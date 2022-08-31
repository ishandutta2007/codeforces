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
//    ll ans = 0;
    vi a(6), b(6);
    for(int i =1; i<6; i++) {
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    b[1]=a[1];
    b[2]=a[3];
    b[3]=a[5];
    b[4]=a[4];
    b[5]=a[2];
    ll h = b[5]+10*b[4]+100*b[3]+1000*b[2]+10000*b[1];
    ll ans = 1;
    for(int i =0; i<5; i++) ans = (ans*h)%(100000);
    string s = to_string(ans);
    while(s.length() < 5) s = "0" + s;
    cout<<s;
    

    
    

}