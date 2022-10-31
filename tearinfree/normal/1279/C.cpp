#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,m,a[100000],b[100000];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<m;i++) scanf("%d",b+i);
        reverse(a,a+n);

        lli ans=0;
        set<int> tr;
        int j=n-1;
        for(int i=0;i<m;i++) {
            if(tr.find(b[i])==tr.end()) {
                do {
                    tr.insert(a[j]);
                }while(a[j--]!=b[i]);
                ans += tr.size() + tr.size() - 1;
            } else {
                ans++;
            }
            tr.erase(b[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}