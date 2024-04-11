#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
char str[1000100];
string ans, ens;

int main() {
    scanf("%s",str);
    n = strlen(str);
    int i;
    for (i=0;i+1<n-2-i;i+=2) {
        int cnt[3] = {0,0,0};
        cnt[str[i]-'a']++;
        cnt[str[i+1]-'a']++;
        cnt[str[n-1-i]-'a']++;
        cnt[str[n-2-i]-'a']++;
        int j=0;
        for (j=0;j<3;j++) if (cnt[j]>1) break;
        ans.push_back(j+'a');
    }
    printf("%s",ans.c_str());
    if (i<=n-1-i) printf("%c",str[i]);
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());

    return 0;
}