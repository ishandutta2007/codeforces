#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,q;
int a[200000];
pair<pair<int,int>,int> queries[200013];
int counts[1000013];
long long ans[200013];

const int SQRT = 450;

pair<pair<int,int>,int> cur2[200013];
int cnt[200013];
void csort(bool which) {
    for (int i=0;i<200013;i++) cnt[i] = 0;
    for (int i=0;i<q;i++) cnt[which ? queries[i].first.second : queries[i].first.first/SQRT]+=1;
    int tot = 0;
    for (int i=0;i<200013;i++) {
        int old = cnt[i];
        cnt[i] = tot;
        tot+=old;
    }
    for (int i=0;i<q;i++) {
        cur2[cnt[which ? queries[i].first.second : queries[i].first.first/SQRT]] = queries[i];
        cnt[which ? queries[i].first.second : queries[i].first.first/SQRT]+=1;
    }
    for (int i=0;i<q;i++) queries[i] = cur2[i];
}

long long cur;
inline void remove1(int i) {
    cur-=(long long) counts[a[i]]*counts[a[i]]*a[i];
    counts[a[i]]-=1;
    cur+=(long long) counts[a[i]]*counts[a[i]]*a[i];
}
inline void add1(int i) {
    cur-=(long long) counts[a[i]]*counts[a[i]]*a[i];
    counts[a[i]]+=1;
    cur+=(long long) counts[a[i]]*counts[a[i]]*a[i];
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<q;i++) scanf("%d%d",&queries[i].first.first,&queries[i].first.second);
    for (int i=0;i<q;i++) queries[i].second = i;
    csort(true);
    csort(false);
    cur = a[0];
    int l = 0;
    int r = 0;
    counts[a[0]]+=1;
    for (int i=0;i<q;i++) {
        int ql = queries[i].first.first-1;
        int qr = queries[i].first.second-1;
        while (l<ql) remove1(l++);
        while (l>ql) add1(--l);
        while (r<qr) add1(++r);
        while (r>qr) remove1(r--);
        ans[queries[i].second] = cur;
    }
    for (int i=0;i<q;i++) printf("%I64d\n",ans[i]);

    return 0;
}