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

long long mod=1000000007;

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
    string s1,s2;
    string t1,t2;
    cin>>t1>>t2;
    s1=t1;
    s2=t2;
    sort(all(s1));
    sort(all(s2));
    if(s2==s1) cout<<"array";
    else {
        int cur = t1.size()-1;
        while (t2.size()>0){
            while(cur>=0 && t1[cur]!=t2.back()) {
                cur--;
            }
            if(cur<0) break;
            cur--;
            t2.pop_back();
        }
        
        if(t2.size()==0) {
            cout<<"automaton";
            return 0;
        }
         cur =s1.length()-1;
        while (s2.size()>0){
            while(cur>=0 && s1[cur]!=s2.back()) {
                cur--;
            }
            if(cur<0) break;
            cur--;
            s2.pop_back();
        }
        if(s2.size() == 0) {
            cout<<"both";
        }
        else {
            cout<<"need tree";
        }
    }
    
}