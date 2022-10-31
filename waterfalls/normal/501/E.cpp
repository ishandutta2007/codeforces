#include <cstdio>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

int n,m;
int a[100013];
int a2[100013];
int num[100013];
set<int> where[100013];
deque<int> left;

bool check(int l, int r) {
    for (int i=0;i<m;i++) a2[i] = a[i];
    if (l<=m/2 && m/2<=r) for (int i=l;i<=r;i++) if (num[a[i]]%2==1) swap(a2[i],a2[m/2]);
    if (m%2==1 && num[a2[m/2]]%2==0) return false;
    for (int i=1;i<=n;i++) where[i].clear();
    for (int i=l;i<=r;i++) if (m%2==0 || i!=m/2) where[a2[i]].insert(i);
    for (int i=0;i<m/2;i++) {
        if (l<=i && i<=r) where[a2[i]].erase(where[a2[i]].begin());
        if (l<=m-i-1 && m-i-1<=r) where[a2[m-i-1]].erase(--where[a2[m-i-1]].end());
        if (a2[i]==a2[m-i-1]) continue;
        int can = 0;
        if (l<=i && i<=r && where[a2[m-i-1]].size()>0) can+=1;
        if (l<=m-i-1 && m-i-1<=r && where[a2[i]].size()>0) can+=2;
        if (!can) return false;
        if (can&1) {
            int which = *where[a2[m-i-1]].begin();
            where[a2[m-i-1]].erase(where[a2[m-i-1]].begin());
            where[a2[i]].insert(which);
            swap(a2[i],a2[which]);
        } else {
            int which = *(--where[a2[i]].end());
            where[a2[i]].erase(--where[a2[i]].end());
            where[a2[m-i-1]].insert(which);
            swap(a2[m-i-1],a2[which]);
        }
    }
    return true;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) num[a[i]]+=1;
    int odds = 0;
    for (int i=1;i<=n;i++) if (num[i]%2==1) odds+=1;
    if (odds>n%2) {
        printf("0\n");
        return 0;
    }
    for (int i=0;i<n;i++) left.push_back(a[i]);
    while (left.size()>1 && left.front()==left.back()) left.pop_front(), left.pop_back();
    if (left.size()<=1) {
        printf("%I64d\n",(long long) n*(n+1)/2);
        return 0;
    }
    m = left.size();
    for (int i=0;i<m;i++) a[i] = left[i];
    for (int i=1;i<=n;i++) num[i] = 0;
    for (int i=0;i<m;i++) num[a[i]]+=1;
    int low = -1;
    int high = m-1;
    while (high-low>1) {
        if (check(0,(low+high+1)/2)) high = (low+high+1)/2;
        else low = (low+high+1)/2;
    }
    int pref = high;
    low = 0;
    high = m;
    while (high-low>1) {
        if (check((low+high)/2,m-1)) low = (low+high)/2;
        else high = (low+high)/2;
    }
    int suff = m-low-1;
    long long diff = (n-m)/2;
    printf("%I64d\n",diff*diff+(diff+1)*(m-pref)+(diff+1)*(m-suff)-1);

    return 0;
}