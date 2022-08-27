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

int n, k;
int curm;
vi a;
vpi ai;
vpi till_plus;
vpi till_minus;
ll ans;
vi suma;

void go(int l, int r) {
    if(l==r) ans++;
    if(r<=l) return;
    //int oldm = curm;
    //while((ai[curm].second<l)||(ai[curm].second>r)) curm--;
    int m = ai[curm].second;
    int v = ai[curm].first%k;
    if((m-l)<(r-m)) {
        for(int i=l; i<=m; i++) {
            till_plus.pb(mp(r, (suma[i-1]+v)%k));
            till_minus.pb(mp(m-1, (suma[i-1]+v)%k));
        }
    }
    else {
        for(int i=m; i<=r; i++) {
            till_plus.pb(mp(m-1, (suma[i]+k-v)%k));
            till_minus.pb(mp(l-2, (suma[i]+k-v)%k));
        }
    }
   // go(l, m-1);
   // go(m+1, r);
   // curm = oldm;
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    scanf("%d %d\n", &n, &k);
    ans=-n;
    a.resize(n+1);
    ll csum=0;
    suma.pb(0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        a[i]=a[i];
        ai.pb(mp(a[i],i));
        csum+=a[i];
        csum=csum%k;
        suma.pb(csum);
    }
    sort(all(ai));
 //   cout<<"AI\n";
 //   for(int i=0; i<n; i++) cout<<ai[i].first<<" "<< ai[i].second<<endl; 
    curm = n-1;
    set<int> breaks;
    breaks.insert(0);
    breaks.insert(n+1);
    for(curm=n-1; curm>=0; curm--) {
        int m = ai[curm].second;
        auto it=(breaks.lower_bound(m));
        auto it2=it;
        --it2;
        go(*it2+1,*it-1);
        breaks.insert(m);
    }
    //go(1, n);
    //sort(all(till_minus));
    //sort(all(till_plus));
    vvi pl(n+1);
    vvi mn(n+1);
    for(auto itm=till_minus.begin(); itm!=till_minus.end(); itm++) {
        if((*itm).first>=0) mn[(*itm).first].pb((*itm).second);
    }
    for(auto itp=till_plus.begin(); itp!=till_plus.end(); itp++) {
        if((*itp).first>=0) pl[(*itp).first].pb((*itp).second);
    }
  //  cout<<"CSUM\n";
 //   for(int i=0; i<=n; i++) cout<<suma[i]<<" "; cout<<endl;
  //  cout<<"TP\n";
   // for(int i=0; i<till_plus.size(); i++) cout<<till_plus[i].first<<"   "<<till_plus[i].second<<endl;
 //   cout<<"TM\n";
 //  for(int i=0; i<till_minus.size(); i++) cout<<till_minus[i].first<<"   "<<till_minus[i].second<<endl;
   // auto itm=till_minus.begin();
   // auto itp=till_plus.begin();
    vi cnt(k, 0);
   // cnt[0]++;
   // while((itm!=till_minus.end())&&((*itm).first<0)) itm++;
   // while((itp!=till_plus.end())&&((*itp).first<0)) itp++;
    for(int i=0; i<=n; i++) {
        cnt[suma[i]]++;
        for(auto it=pl[i].begin(); it!=pl[i].end(); it++) {
            ans+=cnt[*it];
        }
        for(auto it=mn[i].begin(); it!=mn[i].end(); it++) {
            ans-=cnt[*it];
        }
    }
    printf("%I64d", ans);
}