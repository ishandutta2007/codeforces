#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int a, int b) {
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(a,b%a);
}

int n,q;
map<int,int> curCounts;
map<int,int> nextCounts;
map<int,long long> counts;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        nextCounts.clear();
        for (map<int,int>::iterator it=curCounts.begin();it!=curCounts.end();it++) {
            nextCounts[gcd(a,it->first)]+=it->second;
            counts[gcd(a,it->first)]+=it->second;
        }
        nextCounts[a]+=1;
        counts[a]+=1;
        swap(curCounts,nextCounts);
    }
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        int x;
        scanf("%d",&x);
        printf("%I64d\n",counts[x]);
    }

    return 0;
}