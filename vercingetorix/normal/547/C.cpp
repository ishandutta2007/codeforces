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

void alldiv(vi & kr, vpi & ad) {
    int l=kr.size();
    int p2=1;
    for(int i=0; i<l; i++) p2*=2;
    for(int i=1; i<p2; i++){
        int c=i;
        int res=1;
        int num=0;
        for(int j=0; j<l; j++) {
            if(c%2) {
                num++;
                res*=kr[j];
            }
            c/=2;
        }
        ad.pb(mp(res,num));
    }
}


int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    std::vector<std::set<int>> praz(500001);
    std::vector<bool> isp(500001,false);
    
    std::vector<int> p;
    for(int i=2; i<=500000; i++){
        bool f=false;
        for(int j=0; j<upper_bound(all(p), (int)sqrt((double) i))-p.begin();j++) if(i%p[j]==0){
            f=true;
            int xx=i/p[j];
            for(auto k=praz[xx].begin(); k!=praz[xx].end();k++) praz[i].insert(*k);
            praz[i].insert(p[j]);
            break;
        }
        if(f) continue;
        p.push_back(i);
        praz[i].insert(i);
    }
    
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    vb on(n+1, false);
    int num=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    vi div(500011, 0);
    int x;
    ll ans = 0;
    for(int i=0; i<q; i++) {
        cin>>x;
        if(a[x]==1) {
            if(on[x]) {
                on[x]=false;
                num--;
                ans-=num;
            }
            else {
                ans+=num;
                num++;
                on[x]=true;
            }
            cout<<ans<<endl;
            continue;
        }
        //vi & polnraz = praz[a[x]];
        vi kratraz;
        for(auto k= praz[a[x]].begin(); k!= praz[a[x]].end(); k++) kratraz.pb(*k);
        //kratraz.pb(polnraz[0]);
        //for(int j=1; j<polnraz.size(); j++) {
        //    if(polnraz[j]!=polnraz[j-1]) kratraz.pb(polnraz[j]);
        //}
        vpi ad;
        alldiv(kratraz, ad);
        if(on[x]) {
            on[x]=false;
            for(int i=0; i<ad.size(); i++) div[ad[i].first]--;
            num--;
            ll dif=0;
            for(int i=0; i<ad.size(); i++) {
                if(ad[i].second % 2 == 1) dif+=div[ad[i].first];
                else dif-=div[ad[i].first];
            }
            ans-=num-dif;
        }
        else {
            ll dif=0;
            for(int i=0; i<ad.size(); i++) {
                if(ad[i].second % 2 == 1) dif+=div[ad[i].first];
                else dif-=div[ad[i].first];
            }
            ans+=num-dif;
            num++;
            on[x]=true;
            for(int i=0; i<ad.size(); i++) div[ad[i].first]++;
        }
        cout<<ans<<endl;
    }
}