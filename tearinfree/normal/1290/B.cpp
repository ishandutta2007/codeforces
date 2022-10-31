#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

char str[200100];
int cnt[26][200100],n,m;

int main() {
    scanf("%s",str+1);
    n = strlen(str+1);
    scanf("%d",&m);

    for(int i=1;i<=n;i++) {
        for(int j=0;j<26;j++) cnt[j][i] = cnt[j][i-1];
        cnt[str[i]-'a'][i]++;
    }
    while(m--) {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==r) {
            puts("Yes");
            continue;
        } else {
            if(str[l]!=str[r]) {
                puts("Yes");
            } else {
                int ch = str[l]-'a', c = cnt[ch][r]-cnt[ch][l-1];
                c = (r-l+1) - c;
                if(c>=2) {
                    int cc=0;
                    for(int k=0;k<26;k++) if(k!=ch && cnt[k][r]-cnt[k][l-1]) cc++;
                    if(cc>=2) puts("Yes");
                    else puts("No");
                }
                else puts("No");
            }
        }
    }
    return 0;
}