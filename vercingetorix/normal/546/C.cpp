#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
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
    int n;
    cin>>n;
    deque<int> a1, a2;
    int k,x;
    cin>>k;
    for(int i=0; i<k; i++) {
        cin>>x; a1.pb(x);
    }
    cin>>k;
    for(int i=0; i<k; i++) {
        cin>>x; a2.pb(x);
    }
    int t=0;
    for(t=1; t<5000000; t++) {
        int b1=a1.front();
        int b2=a2.front();
        a1.pop_front();
        a2.pop_front();
        if(b1>b2) {
            a1.pb(b2);
            a1.pb(b1);
            if(a2.empty()) break;
        }
        if(b2>b1) {
            a2.pb(b1);
            a2.pb(b2);
            if(a1.empty()) break;
        }
    }
    if(t<5000000) {
        cout<<t<<" ";
        if(a2.empty()) cout<<1;
        else cout<<2;
    }
    else {
        cout<<-1;
    }
}