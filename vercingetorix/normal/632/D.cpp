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

#define pb push_back
#define mp make_pair

ll pow2(ll k, int n) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = pow2(k, n/2);
    return x*x*pow2(k, n%2);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    /*std::vector<std::vector<int>> praz(1000001);
    vi mp(10000001, 0);
    set<int> nn;
    for(int i = 2; i < 1000001; i++) {
        nn.insert(i);
    }
    while (nn.size() > 0) {
        int p = *nn.begin();
        if(p>1000) break;
        vi del;
        for(auto x : nn) {
            if(x%p == 0) {
                mp[x] = p;
                del.pb(x);
            }
        }
        for (auto x:del) nn.erase(x);
    }
    for(auto x:nn) mp[x]=x;*/
   /* std::vector<bool> isp(100001,false);
    
    std::vector<int> p;
    for(int i=2; i<=100000; i++){
        bool f=false;
        for(int j=0; j<p.size();j++) if(i%p[j]==0){
            f=true;
            
            break;
        }
        if(f) continue;
        if (i<1000) p.push_back(i);
        isp[i]=true;
    } */
    int n,m;
    ll ans = 0;
    //cin >> n>>m;
    scanf("%d %d\n", &n, &m);
    map<int, int> num;
    vi a(n);
    vi nok(m+1, 0);
    vi prevnok(m+1, 0);
    //i prevpos();
    for(int i =0 ;i<n;i++){
        //cin>>a[i];
        scanf("%d", &a[i]);
        num[a[i]]++;
    }
    int bestNok = 1;
    int bestNum = 0;
    vi nokn(m+1, 0);
    for(int nok = 1; nok<=m; nok++) {
        int cur= num[nok];
        int nok2 = nok;
        while (nok2 <= m){
            nokn[nok2] += cur;
            nok2+=nok;
        }
        /*nokn[nok]=num[nok];
        int pot=0;
        vi razl;
        int nok2 = nok;
        map<int,int> deg;
        set<int> primes;
        while(nok2 > 1) {
            int ppp = mp[nok2];
            nok2 /= ppp;
            primes.insert(ppp);
        }

        if(nok2>1) {
            razl.pb(nok2);
            primes.insert(nok2);
        }
        vi pp;
        for(auto a:primes) pp.pb(a);
       // cout<<pow2(2, pp.size())<<endl;
        for(int i =1; i<pow2(2, pp.size()); i++){
            int sum =0;
            int div =1;
            int xx = i;
            for(int j=0; j<pp.size(); j++) {
                sum += xx&1;
                div *= pow2(pp[j], xx&1);
                xx>>=1;
            }
           // cout<<div<<"   "<<sum<<endl;
            nokn[nok] -= nokn[nok/div] * pow2(-1, sum);
        }
        while(pdegs.size()<6) pdegs.pb(mp(1,0));
        for(int i1=0; i1<=pdegs[0].second; i1++)
            for(int i2=0; i2<=pdegs[1].second; i2++)
                for(int i3=0; i3<=pdegs[2].second; i3++)
                    for(int i4=0; i4<=pdegs[3].second; i4++)
                        for(int i5=0; i5<=pdegs[4].second; i5++)
                            for(int i6=0; i6<=pdegs[5].second; i6++) {
                                int div = pow(pdegs[0].first, i1)*pow(pdegs[1].first, i2)*pow(pdegs[2].first, i3)*pow(pdegs[3].first, i4)*pow(pdegs[4].first, i5)*pow(pdegs[5].first, i6);
                                pot+=num[div];
                            }
        if(nokn[nok]>bestNum) {
            bestNum=nokn[nok];
            bestNok=nok;
        }*/
    }
    for(int nok = 1; nok<=m; nok++) {
        if(nokn[nok]>bestNum) {
            bestNum=nokn[nok];
            bestNok=nok;
        }
    }
    cout<<bestNok<<" "<<bestNum<<endl;
    for(int i=0; i<n; i++) {
        if(bestNok%a[i]==0) cout<<i+1<<" ";
    }
    
}