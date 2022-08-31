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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

std::vector<std::vector<int>> ch;
std::vector<int> par;
std::vector<std::vector<int>> nb;
std::vector<std::vector<int>> lvl;
std::vector<int> v_lvl;

vi pos, rpos;
vi trav;
vll wcost;
vi wpos;

void bfs(int v) {
    pos[v] = trav.size();
    trav.pb(v);
    for(auto u : ch[v]) bfs(u);
    rpos[v] = trav.size()-1;
}

#pragma once
#include <iterator>
#include <cassert>
#include <vector>

using std::vector;

template<typename T>
struct IncreaseBy
{
public:
    IncreaseBy(T value = T()) : value_(std::move(value)) {}
    
    friend IncreaseBy<T> operator*(const IncreaseBy<T>& lh, const IncreaseBy<T>& rh) { return{ lh.value_ + rh.value_ }; }
    T value_;
};

template<typename UpdateType, typename BinaryFunctor>
struct UpdateApplier
{};

template<typename T, typename IdempotentFunctor>
struct UpdateApplier<IncreaseBy<T>, IdempotentFunctor>
{
    static T apply(const T& v, const IncreaseBy<T>& upd, size_t)
    {
        return v + upd.value_;
    }
};

template<typename ValueType, class AggregatingFunction, class UpdateType>
class SegmentTree
{
public:
    SegmentTree(const vector<ValueType>& initialValues, AggregatingFunction aggregatingFunction)
    : aggregatingFunction_(aggregatingFunction), size_(initialValues.size())
    {
        auto heapSize = (size_t(1) << calcHeight_(size_)) - 1;
        valuesHeap_.resize(heapSize);
        lazyUpdatesHeap_.resize(heapSize);
        build_(begin(initialValues), end(initialValues), 0);
    }
    
    void updateElement(size_t i, UpdateType upd)
    {
        updateRange(i, i + 1, upd);
    }
    
    void updateRange(size_t l, size_t r, UpdateType upd)
    {
        if (l == r) return;
        update_(l, r, upd, 0, 0, size_);
    }
    
    ValueType getValueOnSegment(size_t l, size_t r) const
    {
        return calcValueOnSegment_(l, r, UpdateType(), 0, 0, size_);
    }
    
private:
    typedef typename vector<ValueType>::const_iterator Iterator;
    
    void build_(Iterator left, Iterator right, size_t ind)
    {
        if (right - left == 1)
        {
            valuesHeap_[ind] = *left;
        }
        else
        {
            auto center = left + (right - left) / 2;
            build_(left, center, leftChild_(ind));
            build_(center, right, rightChild_(ind));
            valuesHeap_[ind] = aggregatingFunction_(valuesHeap_[leftChild_(ind)], valuesHeap_[rightChild_(ind)]);
        }
    }
    
    void update_(size_t l, size_t r, const UpdateType& upd, size_t nodeInd, size_t nodeLeft, size_t nodeRight)
    {
        if (l == nodeLeft && r == nodeRight)
        {
            lazyUpdatesHeap_[nodeInd] = upd * lazyUpdatesHeap_[nodeInd];
            return;
        }
        
        lazyUpdatesHeap_[leftChild_(nodeInd)] = lazyUpdatesHeap_[nodeInd] * lazyUpdatesHeap_[leftChild_(nodeInd)];
        lazyUpdatesHeap_[rightChild_(nodeInd)] = lazyUpdatesHeap_[nodeInd] * lazyUpdatesHeap_[rightChild_(nodeInd)];
        lazyUpdatesHeap_[nodeInd] = UpdateType();
        
        auto nodeCenter = (nodeLeft + nodeRight) / 2;
        if (r <= nodeCenter)
        {
            update_(l, r, upd, leftChild_(nodeInd), nodeLeft, nodeCenter);
        }
        else if (l >= nodeCenter)
        {
            update_(l, r, upd, rightChild_(nodeInd), nodeCenter, nodeRight);
        }
        else
        {
            update_(l, nodeCenter, upd, leftChild_(nodeInd), nodeLeft, nodeCenter);
            update_(nodeCenter, r, upd, rightChild_(nodeInd), nodeCenter, nodeRight);
        }
        
        valuesHeap_[nodeInd] = aggregatingFunction_(calcValueOnSegment_(nodeLeft, nodeCenter, {}, leftChild_(nodeInd), nodeLeft, nodeCenter),
                                                    calcValueOnSegment_(nodeCenter, nodeRight, {}, rightChild_(nodeInd), nodeCenter, nodeRight));
    }
    
    static size_t leftChild_(size_t ind) { return 2 * ind + 1; }
    static size_t rightChild_(size_t ind) { return 2 * ind + 2; }
    
    ValueType calcValueOnSegment_(size_t l, size_t r, UpdateType upd, size_t nodeInd, size_t nodeLeft, size_t nodeRight) const
    {
        upd = upd * lazyUpdatesHeap_[nodeInd];
        if (l == nodeLeft && r == nodeRight)
            return UpdateApplier<UpdateType, AggregatingFunction>::apply(valuesHeap_[nodeInd], upd, r - l);
        
        auto nodeCenter = (nodeLeft + nodeRight) / 2;
        
        if (r <= nodeCenter)
            return calcValueOnSegment_(l, r, upd, leftChild_(nodeInd), nodeLeft, nodeCenter);
        else if (l >= nodeCenter)
            return calcValueOnSegment_(l, r, upd, rightChild_(nodeInd), nodeCenter, nodeRight);
        else
            return aggregatingFunction_(calcValueOnSegment_(l, nodeCenter, upd, leftChild_(nodeInd), nodeLeft, nodeCenter),
                                        calcValueOnSegment_(nodeCenter, r, upd, rightChild_(nodeInd), nodeCenter, nodeRight));
    }
    
    int calcHeight_(size_t length) const
    {
        int result = 1;
        size_t maxLen = 1;
        while (length > maxLen)
        {
            maxLen *= 2;
            result++;
        }
        return result;
    }
    
private:
    const AggregatingFunction aggregatingFunction_;
    
    size_t size_;
    vector<ValueType> valuesHeap_;
    vector<UpdateType> lazyUpdatesHeap_;
};

template<typename ValueType, class AggregatingFunction, class UpdateType>
SegmentTree<ValueType, AggregatingFunction, UpdateType>
makeSegmentTree(const vector<ValueType>& initialValues, AggregatingFunction aggregatingFunction, UpdateType dummy)
{
    return SegmentTree<ValueType, AggregatingFunction, UpdateType>(initialValues, aggregatingFunction);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    ch = std::vector<std::vector<int>>(n+1);
    par = std::vector<int>(n+1);
    nb = std::vector<std::vector<int>>(n+1);
    lvl = std::vector<std::vector<int>>(n+1);
    v_lvl =std::vector<int>(n+1,0);
    pos = vi(n+1);
    rpos  = vi(n+1);
    
    int mm=1;
    lvl[1].push_back(1);
    v_lvl[1]=1;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        nb[u].push_back(v);
        nb[v].push_back(u);
        //xp;
    }
    int l=2;
    
    while(mm<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    mm++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    std::vector<long long> lsize(l+1);
    for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();
    bfs(1);
    vi rs(m), re(m), cost(m);
    vvi inds(n+1);
    vvi inde(n+1);
    wpos = vi(m);
    forn(i,0,m) {
        scanf("%d %d %d", &re[i], &rs[i], &cost[i]);
        inds[rs[i]].pb(i);
        inde[re[i]].pb(i);
    }
    vi ws(n+1);
    vi we(n+1);
    forn(i,0,n) {
        int v= trav[i];
        ws[v] = wcost.size();
        for(auto p : inde[v]) {
            wpos[p] = wcost.size();
            wcost.pb(cost[p]);
        }
        we[v] = wcost.size() - 1;
    }
    for(int i = n-1; i>=0; i--) {
        int v = trav[i];
        we[v] = we[trav[rpos[v]]];
    }
    ll ans = 0;
    
    //build segtree wcost
    auto st = makeSegmentTree(wcost, [](ll a, ll b) {return min(a,b);}, IncreaseBy<ll>());
    for(int lev = l; lev>1; lev--) {
        for(auto v : lvl[lev]) {
            for(auto p : inds[v]) {
                //set seg (wpos[p]) 10^16
                st.updateElement(wpos[p], IncreaseBy<ll>(20000000000000000));
//                wcost[wpos[p]] = 10000000000000000;
            }
            ans += 0;//min seg (ws[v], we[v])
            if(we[v]<ws[v]) {
                cout<<-1;
                return 0;
            }
            ll cmin = st.getValueOnSegment(ws[v], we[v]+1);
//            ll cmin = 10000000000000000;
//            for(int j = ws[v]; j<=we[v]; j++) cmin = min(cmin, wcost[j]);
            ans+=cmin;
            //reduce seg(ws[v], we[v]) for min seg (ws[v], we[v])
//            for(int j = ws[v]; j<=we[v]; j++) wcost[j]-=cmin;
            st.updateRange(ws[v], we[v]+1, IncreaseBy<ll>(-cmin));
        }
    }
    if(ans>10000000000000000) ans = -1;
    cout<<ans;
}