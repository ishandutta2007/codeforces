#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
const int maxn = 100300;
int n, k, a[maxn];
vector<int> ans;
ll sum;

int main(){
    scanf("%d%d", &n, &k);
    rep(i, n) scanf("%d", &a[i]), sum += a[i];
    if(sum % k) {puts("No"); return 0;}
    int per = sum / k, cur = 0, cnt = 0;
    for(int i = 1; i <= n; ++i) {
        cur += a[i];
        if(cur > per) {puts("No"); return 0;}
        if(cur == per) ans.push_back(cnt+1), cur = 0, cnt = 0;
        else cnt++;
    }
    printf("Yes\n");
    for(int i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
    return 0;
}