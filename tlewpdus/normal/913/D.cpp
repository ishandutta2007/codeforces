#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int a[200100], t[200100], T, n, ord[200100], tsum, maxi;
priority_queue<pii> pq;

int main() {
    int i;

    scanf("%d%d",&n,&T);
    for (i=0;i<n;i++) {scanf("%d%d",&a[i],&t[i]);ord[i]=i;}
    sort(ord,ord+n,[](int p, int q){return a[p]<a[q];});
    int j = n-1, ti = n;
    for (i=n;i>0;i--) {
        while(~j&&a[ord[j]]>=i) {pq.push(pii(t[ord[j]],ord[j])); tsum += t[ord[j]]; j--;}
        while(!pq.empty()&&(tsum>T||pq.size()>i)) {tsum-=pq.top().first;pq.pop();}
        if (maxi<pq.size()) {maxi=pq.size();ti=i;}
    }
    printf("%d\n%d\n",maxi,maxi);
    while(!pq.empty()) pq.pop(); tsum = 0;
    for (j=n-1;~j&&a[ord[j]]>=ti;j--) {pq.push(pii(t[ord[j]],ord[j])); tsum += t[ord[j]];}
    while(!pq.empty()&&(tsum>T||pq.size()>ti)) {tsum-=pq.top().first;pq.pop();}
    while(!pq.empty()) {printf("%d ",pq.top().second+1); pq.pop();} printf("\n");

    return 0;
}