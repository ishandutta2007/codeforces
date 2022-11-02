#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n,k;
long long ans;
long long S;
int a[25];
long long fact[19];
unordered_map<long long,int> ways;

void solve(int where, int last, long long cur, int used, bool one) {
    if (where==last) {
        if (one) ways[26*cur+used]+=1;
        else for (int i=0;i+used<=k;i++) ans+=ways[26*(S-cur)+i];
    } else {
        if (a[where]<=18 && used<k && cur+fact[a[where]]<=S) solve(where+1,last,cur+fact[a[where]],used+1,one);
        solve(where+1,last,cur,used,one);
        if (cur+a[where]<=S) solve(where+1,last,cur+a[where],used,one);
    }
}

int main() {
    fact[0] = 1;
    for (int i=1;i<19;i++) fact[i] = fact[i-1]*i;
    scanf("%d%d%I64d",&n,&k,&S);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    solve(0,n/2+1,0,0,1);
    ans = 0;
    solve(n/2+1,n,0,0,0);
    printf("%I64d\n",ans);

    return 0;
}