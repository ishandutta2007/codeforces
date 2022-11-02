#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Event { int l,r,type,viewers,id; };
bool comp(Event a, Event b) {
    if (a.r==b.r) return a.type<b.type;
    return a.r<b.r;
}

int dist[800013];
class ST {
private:
    int size;
    int st[3200013];
    int lazy[3200013];
    int left(int w) { return (w<<1); }
    int right(int w) { return (w<<1)+1; }
    void process(int w, int L, int R) {
        st[w] = max(st[w],lazy[w]);
        if (L!=R) {
            lazy[left(w)] = max(lazy[left(w)],lazy[w]);
            lazy[right(w)] = max(lazy[right(w)],lazy[w]-(dist[(L+R)/2+1]-dist[L]));
        }
        lazy[w] = 0;
    }
    void updateI(int w, int L, int R, int a, int b, int val) {
        if (lazy[w]) process(w,L,R);
        if (b<L || R<a) return;
        if (a<=L && R<=b) lazy[w] = val-(dist[L]-dist[a]), process(w,L,R);
        else {
            updateI(left(w),L,(L+R)/2,a,b,val);
            updateI(right(w),(L+R)/2+1,R,a,b,val);
            st[w] = max(st[left(w)],st[right(w)]);
        }
    }
    int queryI(int w, int L, int R, int a, int b) {
        if (lazy[w]) process(w,L,R);
        if (b<L || R<a) return 0;
        if (a<=L && R<=b) return st[w];
        int one = queryI(left(w),L,(L+R)/2,a,b);
        int two = queryI(right(w),(L+R)/2+1,R,a,b);
        return max(one,two);
    }
public:
    ST(int s=0) {
        size = s;
        fill(st,st+4*size,0);
        fill(lazy,lazy+4*size,0);
    }
    void update(int a, int b, int val) { updateI(1,0,size-1,a,b,val); }
    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

int n,m;
vector<Event> events;
vector<int> times;
unordered_map<int,int> id;
ST tree;
long long best;
Event which;

void go() {
    for (int i=0;i<events.size();i++) {
        if (events[i].type==0) tree.update(id[events[i].l],id[events[i].r],events[i].r-events[i].l);
        else {
            int cur = tree.query(id[events[i].l],id[events[i].r]);
            if ((long long) cur*events[i].viewers>best) best = (long long) cur*events[i].viewers, which = events[i];
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        Event next;
        scanf("%d%d",&next.l,&next.r);
        times.push_back(next.l); times.push_back(next.r);
        next.type = 0; next.id = i;
        events.push_back(next);
    }
    for (int i=0;i<m;i++) {
        Event next;
        scanf("%d%d%d",&next.l,&next.r,&next.viewers);
        times.push_back(next.l); times.push_back(next.r);
        next.type = 1; next.id = i;
        events.push_back(next);
    }
    sort(times.begin(),times.end());
    times.erase(unique(times.begin(),times.end()),times.end());
    sort(events.begin(),events.end(),comp);
    for (int i=0;i<times.size();i++) id[times[i]] = id.size(), dist[id.size()] = times[i];
    tree = ST(times.size()+1);
    best = 0;
    go();
    swap(which.l,which.r);
    which.l = 1000000000-which.l; which.r = 1000000000-which.r;
    times.clear();
    for (int i=0;i<events.size();i++) {
        int sw = 0;
        if (events[i].type==1 && tree.query(id[events[i].l],id[events[i].l])>=events[i].r-events[i].l) {
            if ((long long) (events[i].r-events[i].l)*events[i].viewers>best) {
                best = (long long) (events[i].r-events[i].l)*events[i].viewers, sw = 1;
            }
        }
        swap(events[i].l,events[i].r);
        events[i].l = 1000000000-events[i].l; events[i].r = 1000000000-events[i].r;
        if (sw) which = events[i];
        times.push_back(events[i].l); times.push_back(events[i].r);
    }
    sort(times.begin(),times.end());
    times.erase(unique(times.begin(),times.end()),times.end());
    sort(events.begin(),events.end(),comp);
    id.clear();
    for (int i=0;i<times.size();i++) id[times[i]] = id.size(), dist[id.size()] = times[i];
    tree = ST(times.size()+1);
    go();
    printf("%I64d\n",best);
    if (best!=0) {
        for (int i=0;i<events.size();i++) {
            if (events[i].type==0 && min(events[i].r,which.r)-max(events[i].l,which.l)==best/which.viewers) {
                printf("%d %d\n",events[i].id+1,which.id+1);
                break;
            }
        }
    }

    return 0;
}