#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Query { int l,r; double p; };
bool comp(Query a, Query b) {
    if (a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}

int n,q;
int a[100013];
vector<Query> queries;
int highest;
class Offset {
private:
    double prob2[10013];
    int offset;
public:
    Offset(int large=0) { offset = large-5003; fill(prob2,prob2+10013,0); }
    double& operator[](int i) { return prob2[max(i-offset,0)]; }
};
int done[5013];
Offset prob[5013];
double cur[10013];
bool needs[5013][5013];

void solve(int x) {
    done[x] = 1;
    int left = n+2;
    int right = 0;
    for (int i=0;i<=q;i++) {
        if (queries[x].l>queries[i].l || queries[i].r>queries[x].r || done[i]) continue;
        left = min(left,queries[i].l);
        right = max(right,queries[i].r);
        needs[x][i] = 1;
        solve(i);
    }
    if (left==n+2) {
        int large = 0;
        for (int i=queries[x].l;i<=queries[x].r;i++) large = max(large,a[i]);
        prob[x][large] = 1-queries[x].p;
        prob[x][large+1] = queries[x].p;
    } else {
        for (int i=highest-5003;i<=highest+5003;i++) prob[5012][i] = 1;
        for (int other=0;other<=q;other++) {
            if (!needs[x][other]) continue;
            for (int j=highest-5002;j<=highest+5001;j++) prob[5012][j]*=prob[other][j];
        }
        for (int i=highest-5001;i<=highest+5001;i++) prob[5011][i] = prob[5012][i]-prob[5012][i-1];
        int large = -1;
        for (int i=queries[x].l;i<left;i++) large = max(large,a[i]);
        for (int i=right+1;i<=queries[x].r;i++) large = max(large,a[i]);
        if (large!=-1) {
            double under = 0;
            for (int i=highest-5002;i<=large;i++) under+=prob[5011][i], prob[5011][i] = 0;
            prob[5011][large] = under;
        }
        for (int i=highest-5001;i<=highest+5001;i++) {
            prob[x][i] = queries[x].p*prob[5011][i-1]+(1-queries[x].p)*prob[5011][i];
        }
    }
    for (int i=highest-5001;i<=highest+5001;i++) prob[x][i]+=prob[x][i-1];
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    highest = 0;
    for (int i=0;i<n;i++) highest = max(highest,a[i]);
    for (int i=0;i<5013;i++) prob[i] = Offset(highest);
    for (int i=1;i<=q;i++) {
        int l,r; double p;
        scanf("%d%d%lf",&l,&r,&p);
        l-=1; r-=1;
        Query next;
        next.l = l, next.r = r, next.p = p;
        queries.push_back(next);
    }
    sort(queries.begin(),queries.end(),comp);
    Query first;
    first.l = 0, first.r = n-1, first.p = 0;
    queries.insert(queries.begin(),first);
    first.l = n+2; first.r = n+2;
    queries.push_back(first);
    solve(0);
    double ans = 0;
    for (int i=highest;i<=highest+5000;i++) ans = ans+i*(prob[0][i]-prob[0][i-1]);
    printf("%1.9f\n",ans);

    return 0;
}