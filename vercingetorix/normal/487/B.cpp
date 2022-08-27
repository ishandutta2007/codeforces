#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

const long long mod = 1000000007;

class SlideMin{
public:
    SlideMin() : curlpos(0), currpos(0) { };
    void push_right(long n);
    void pop_left();
    long get_min();
    long get_len();
    std::deque<std::pair<long, long>> mon_queue;
    long curlpos;
    long currpos;
};

void SlideMin::pop_left() {
    if(curlpos+1>=currpos) return;
    curlpos++;
    while((mon_queue.size()>0)&&(mon_queue.front().second <= curlpos)) mon_queue.pop_front();
}

long SlideMin::get_len() {
    return currpos-curlpos;
}

long SlideMin::get_min() {
    if(currpos==curlpos) return 0;
    return mon_queue.front().first;
}

void SlideMin::push_right(long n) {
    currpos++;
    while((mon_queue.size()>0)&&(mon_queue.back().first >= n)) mon_queue.pop_back();
    mon_queue.push_back(make_pair(n,currpos));
}

class SlideMax{
public:
    SlideMax() : curlpos(0), currpos(0) { };
    void push_right(long n);
    void pop_left();
    long get_max();
    long get_len();
    std::deque<std::pair<long, long>> mon_queue;
    long curlpos;
    long currpos;
};

void SlideMax::pop_left() {
    if(curlpos+1>=currpos) return;
    curlpos++;
    while((mon_queue.size()>0)&&(mon_queue.front().second <= curlpos)) mon_queue.pop_front();
}

long SlideMax::get_len() {
    return currpos-curlpos;
}

long SlideMax::get_max() {
    if(currpos==curlpos) return 0;
    return mon_queue.front().first;
}

void SlideMax::push_right(long n) {
    currpos++;
    while((mon_queue.size()>0)&&(mon_queue.back().first <= n)) mon_queue.pop_back();
    mon_queue.push_back(make_pair(n,currpos));
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
    int n,s,l,x,y;
    int ans=0;
    cin>>n>>s>>l;
    vi a;
    vi g(n+1);
    vi f(n+1);
    SlideMin smin;
    SlideMax smax;
    for(int i=1;i<=n;i++){
        cin>>x;
        a.pb(x);
        smin.push_right(x);
        smax.push_right(x);
        while((smax.get_max()-smin.get_min())>s){
            smin.pop_left();
            smax.pop_left();
        }
        g[i]=smin.get_len();
    }
    SlideMin fmin;
    for(int i=1; i<=n; i++){
        if(g[i]<l){
            f[i]=999999;
            continue;
        }
        if(g[i]==i) {
            f[i]=1;
            continue;
        }
        while(fmin.currpos<i-l) fmin.push_right(f[fmin.currpos+1]);
        while(fmin.curlpos<i-g[i]-1) fmin.pop_left();
        if(fmin.get_min()==999999) f[i]=999999;
        else f[i]=fmin.get_min()+1;
    }
    if(f[n]==999999) cout<<-1;
    else cout<<f[n];
    return 0;
}