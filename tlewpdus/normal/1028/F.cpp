#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

ll gcd(ll a, ll b) {
    if (!a)return b;
    return gcd(b%a,a);
}

map<pll,int> mpi;
map<ll,int> ms;
int p;
set<pll> se[100100];

void inp(pll a, int v) {
    ll g = gcd(a.first,a.second);
    a = pll(a.first/g,a.second/g);
    //printf("%lld, %lld : %d\n",a.first,a.second,v);
    if (mpi.find(a)==mpi.end()) mpi[a]=v;
    else mpi[a]+=v;
}

void era(pll a, int v) {
    ll g = gcd(a.first,a.second);
    a = pll(a.first/g,a.second/g);
    //printf("%lld, %lld : %d\n",a.first,a.second,-v);
    mpi[a]-=v;
}

void ins(int idx, pll v) {
    auto it = se[idx].begin();
    while(it!=se[idx].end()) {
        pll p = pll((*it).first+v.first,(*it).second+v.second);
        inp(p,2);
        it++;
    }
    inp(v,1);
    se[idx].insert(v);
}

void del(int idx, pll v) {
    se[idx].erase(v);
    era(v,1);
    auto it = se[idx].begin();
    while(it!=se[idx].end()) {
        pll p = pll((*it).first+v.first,(*it).second+v.second);
        era(p,2);
        it++;
    }
}

int main() {
    int i, ans = 0;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        int a; ll x, y;
        scanf("%d%lld%lld",&a,&x,&y);
        if (a==1) {
            ll v = x*x+y*y;
            if (ms.find(v)!=ms.end()) {
                ins(ms[v],pll(x,y));
            }
            else {
                ms[v] = p;
                se[p].insert(pll(x,y));
                inp(pll(x,y),1);
                p++;
            }
            ans++;
        }
        else if (a==2) {
            ll v = x*x+y*y;
            del(ms[v],pll(x,y));
            ans--;
        }
        else {
            ll g = gcd(x,y);
            printf("%d\n",ans-mpi[pll(x/g,y/g)]);
        }
    }

    return 0;
}