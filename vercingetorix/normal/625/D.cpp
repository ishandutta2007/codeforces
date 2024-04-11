#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
deque<int> num;
deque<int> num2;
#define pb push_back
#define mp make_pair
string pos;
bool test(deque<int> & n) {
    int cur = 0;
    int l =n.size();
    deque<int> ansl, ansr;
    while(cur<=(l-1)/2) {
        int cur2 = l-1-cur;
        //int d1=n[cur];
        //int d2=n[cur2];
        //if(n[cur2]<0) return false;
        if(cur==cur2) {
            if(n[cur] % 2 != 0) return false;
            ansl.pb(n[cur]/2);
            break;
        }
        if(n[cur]>n[cur2]+1) {
            n[cur2]+=10;
            n[cur2-1] -= 1;
        }
        if(n[cur]>n[cur2]) {
            n[cur]--;
            n[cur+1] += 10;
        }
        if(n[cur2] >18) return false;
        if(n[cur]!=n[cur2]) return false;
        if(n[cur]<0) return false;
        ansl.pb((n[cur]+1)/2);
        ansr.push_front(n[cur] - ansl.back());
        cur++;
    }
    if(ansl[0]==0) return false;
    for(auto x: ansl) cout<<x;     for(auto x: ansr) cout<<x;
    pos.clear();
    for(auto x: ansl) pos+=to_string(x);     for(auto x: ansr) pos+=to_string(x);
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
   //for(int i = 1; i<=101000; i++) {
        string gen = to_string(1);
        reverse(all(gen));
        num.clear();
        num2.clear();
        int n,m;
        ll ans = 0;
        string s;
        getline(cin, s);
        //s=to_string(i + stoi(gen));
        //s = to_string(i);
        for(auto c: s) num.pb(c-'0');
        num2 = num;
        if(num.size()>1) {
            if(num[0]==1) {
                num2[1]+=10;
                num2.pop_front();
            }
        }
       // cout<<i<< "    ";
   // cout<<s<<endl;
    if(!test(num)) if(!test(num2)) {cout<<0;}//<<"  "<<endl; cout<<s<<"  "; cout<<i + stoi(gen); return 0; continue;}
        //cout<<pos << "   and the sum is  ";
    //
     //  int x = stoi(pos);reverse(all(pos));int y =stoi(pos);if (x+y!=i+stoi(gen)) {cout<<i+stoi(gen);return 0;}
    //}
}