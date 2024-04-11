#include <bits/stdc++.h>

using namespace std;

struct data {
    int c, t;
};

int n, q;
int lrr[600100];

struct lazy {
    int len[2100000], val[2100000];
    data rem[2100000], dat[2100000];
    void init(int s = 0, int e = n-1, int idx = 1) {
        rem[idx] = dat[idx] = data{1,-1};
        if (s==e) {
            val[idx] = len[idx] = lrr[s];
            return;
        }
        int m = (s+e)>>1;
        init(s,m,idx*2); init(m+1,e,idx*2+1);
        val[idx] = len[idx] = len[idx*2]+len[idx*2+1];
    }
    void mer(int i, int j) {
        if (dat[i].t<rem[j].t) {
            rem[i] = rem[j];
            dat[i] = rem[j];
            val[i] = len[i]*rem[j].c;
        }
    }
    void pd(int idx) {
        mer(idx*2,idx);
        mer(idx*2+1,idx);
    }
    void que(int S, int E, int C, int T, int s = 0, int e = n-1, int idx = 1) {
        if (e<S||E<s) return;
        if (S<=s&&e<=E) {
            dat[idx] = rem[idx] = data{C,T};
            val[idx] = len[idx]*C;
            return;
        }
        int m = (s+e)>>1;
        pd(idx);
        que(S,E,C,T,s,m,idx*2); que(S,E,C,T,m+1,e,idx*2+1);
        val[idx] = val[idx*2]+val[idx*2+1];
    }
} lst;

int l[300100], r[300100], c[300100];

int main() {
    int i;

    scanf("%d%d",&n,&q);
    vector<int> comp;
    for (i=0;i<q;i++) {
        scanf("%d%d%d",&l[i],&r[i],&c[i]); l[i]--; c[i]--;
        comp.push_back(l[i]); comp.push_back(r[i]);
    }
    comp.push_back(0); comp.push_back(n);
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    n = (int)comp.size()-1;

    for (i=0;i<n;i++) {
        lrr[i] = comp[i+1]-comp[i];
    }
    for (i=0;i<q;i++) {
        l[i] = lower_bound(comp.begin(),comp.end(),l[i])-comp.begin();
        r[i] = lower_bound(comp.begin(),comp.end(),r[i])-comp.begin()-1;
    }
    lst.init();
    for (i=0;i<q;i++) {
        lst.que(l[i],r[i],c[i],i);
        printf("%d\n",lst.val[1]);
    }

    return 0;
}