#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <stdio.h>
#include <cassert>

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
struct group;

struct group {
    ll num;
    ll sum;
    ll sumr;
    ll numr;
    list<group>::iterator pos;
};

struct comp{
    bool operator()(const group & a, const group & b) {
        return (a.sum * b.num > b.sum * a.num);
    }
};

ll best(vll & a) {
    ll ans=0;
    list<group> num;
    set<group, comp> comps;
    vll ch(a.size());
    ll sum=0;
    ll delr=0;
    ll delsum=0;
    for(int i = a.size()-1; i>=0; i--) {
        ch[i] = sum;
        sum += a[i];

    }
    for(ll i =0; i<a.size(); i++) {
        group newg;
        newg.num = 1;
        newg.sumr = ch[i];
        newg.sum = a[i];
        newg.numr = a.size() - i-1;
        
        num.push_back(newg);
        num.back().pos = --(num.end());
       // cout<<num.back().num<<endl;
        comps.insert(num.back());
    }
    while(comps.size() > 0) {
        auto aa  = comps.begin();
        auto it = aa->pos;
        it++;
        if (it == num.end()) {
            delr += aa->num;
            delsum += aa->sum;
            int k = num.size();
            num.erase(aa->pos);
            assert(num.size() == k-1);
            comps.erase(aa);
            
        }
        else {
            if(aa->num == 1) ans = max(ans, aa->sum * (aa->numr - delr) - aa->sumr + delsum);
            auto bb = *it;

            group c;
            c.num=aa->num+bb.num;
            c.sum=aa->sum+bb.sum;
            c.pos = aa->pos;
            c.sumr = aa->sumr;
            c.numr = aa->numr;
            *(aa->pos) = c;
            comps.erase(aa);
            comps.erase(bb);
            comps.insert(c);
            int k = num.size();
            num.erase(it);
            assert(num.size() == k-1);
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
    ll ans = 0;
    //cin >> n;
    scanf("%I64d", &n);
    vll a;
    a.resize(n);
    for(int i =0;i<n;i++) scanf("%I64d", &a[i]);
    vll b= a;
    reverse(all(b));
    for(ll i =0;i<n;i++) b[i]=-b[i];
    for(ll i=1;i<=n;i++) ans+=a[i-1]*i;
    
    
    printf("%I64d", ans+max(best(a), best(b)));
}