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
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    set<pair<int, int>> ord;
    for(int i=0; i<n; i++) {
        ord.insert(mp(i, (int)(s[i]-'a')));
    }
    ord.insert(mp(n,-1));
    for(int i=0; i<q; i++) {
        int l,r,k;
        cin>>l>>r>>k;
        l--; r--;
        vpi toerase;
        auto itl=ord.lower_bound(mp(l,0));
        auto itr=ord.lower_bound(mp(r,0));
        if(itl->first>l) itl--;
        if(itr->first==r) itr++;
        int last;
        auto previt=itl;
        auto it=itl;
        it++;
        if(it==itr) continue;
        vi count(26,0);
        for (; it!=itr; it++) {
            count[previt->second]+=min(it->first-previt->first, it->first-l);
            previt=it;
            last=it->second;
            //ord.erase(it);
            toerase.pb(*it);
        }
       // cout<<previt->first<<' '<<previt->second;
        count[previt->second]+=r-previt->first+1;
        if(itr->first>r+1) ord.insert(mp(r+1,last));
        if(l==itl->first) ord.erase(itl);
        //toerase.pb(*itl);
        for(int j=0; j<toerase.size(); j++) {
            ord.erase(toerase[j]);
        }
       
        int cur=l;
        if(k==1) {
            for(int j=0; j<26; j++) {
                if(count[j]>0) {
                    ord.insert(mp(cur, j));
                    cur+=count[j];
                }
            }
        }
        else {
            for(int j=25; j>=0; j--) {
                if(count[j]>0) {
                    ord.insert(mp(cur, j));
                    cur+=count[j];
                }
            }
        }
    }
    for(auto it=ord.begin(); it!=(--ord.end()); it++) {
        auto itn=it;
        itn++;
        int xx=itn->first-it->first;
        char c='a'+it->second;
        for(int i=0;i<xx;i++) cout<<c;
    }
}