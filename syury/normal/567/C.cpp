#include<cstdio>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

const long long int gmin = -1e9, gmax = 1e9;

vector<long long int> dp1, dp2, dp3;
int n, k;
vector<int> a;
map<int, long long int> nums1, nums2;
long long int ans = 0ll;

int main(){
    scanf("%d%d", &n, &k);
    dp1.resize(n); dp1.assign(n, 1);
    dp2.resize(n); dp2.assign(n, 0);
    dp3.resize(n); dp3.assign(n, 0);
    a.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = a.size() - 1; i >= 0; i--){
        long long int nxt1 = a[i] * 1ll * k;
        if(!(gmin <= nxt1 && gmax >= nxt1)){nums1[a[i]]++; continue;}
        dp2[i] = nums1[(int)nxt1];
        nums1[a[i]]++;
        dp3[i] = nums2[(int)nxt1];
        nums2[a[i]] += dp2[i];
        ans += dp3[i];
    }
    printf("%lld", ans);
    return 0;
}