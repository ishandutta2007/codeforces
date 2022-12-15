#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MN = 3e5+5;
ll A, B, C, i, j, x, y; ll tot, hm, hmm, ans=1LL<<60;
vl vec;

int main(){
    scanf("%lld%lld%lld",&A,&B,&C);
    hm = 0; hmm = 1LL<<60;
    for(i=1;i<=A;i++){
        scanf("%lld",&x);
        tot += x; hm += x;
        hmm = min(hmm, x);
    }
    vec.push_back(hmm);
    ans = min(ans, hm);
    hm = 0; hmm = 1LL<<60;
    for(i=1;i<=B;i++){
        scanf("%lld",&x);
        tot += x; hm += x;
        hmm = min(hmm, x);
    }
    vec.push_back(hmm);
    ans = min(ans, hm);
    hm = 0; hmm = 1LL<<60;
    for(i=1;i<=C;i++){
        scanf("%lld",&x);
        tot += x; hm += x;
        hmm = min(hmm, x);
    }
    vec.push_back(hmm);
    ans = min(ans, hm);
    sort(vec.begin(),vec.end());
    ans = min(ans, vec[0]+vec[1]);
    printf("%lld\n",tot-2*ans);
    return 0;
}