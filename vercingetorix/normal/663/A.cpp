#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
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

long long mod=1000003;

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
    string s;
    cin>>s;
//    cout<<s;
    vi a;
    a.pb(1);
    cin>>s;
    while(s != "=") {
        
        if(s=="-")
            a.pb(-1);
        else a.pb(1);
        cin>>s;
        cin>>s;
    }
    int n;
    cin>>n;
    int ap=0, am=0;
    for(auto x:a) {
        if(x>0) ap++;
        else am++;
    }
    if(n*ap - am < n) cout<<"Impossible";
    else if(ap-n*am>n) cout<<"Impossible";
    else {
        cout<<"Possible"<<endl;
        int add = n - (ap-am);
        string ans;
        for(int i = 0; i<a.size(); i++) {
            if(i>0) {
                if(a[i]>0) cout<<"+ ";
                else cout << "- ";
            }

            if(a[i]>0) {
                if(add>0) {
                    int d = min(n-1, add);
                    cout<<1+d<<" ";
                    add-=d;
                }
                else cout<<"1 ";
            }
            if(a[i]<0) {
                if(add<0) {
                    int d = max(-n+1, add);
                    cout<<1-d<<" ";
                    add-=d;
                }
                else cout<<"1 ";
            }
        }
        cout<<"= "<<n<<endl;
    }
    //for(auto x:a) cout<<x<<" ";
}