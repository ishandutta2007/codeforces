#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans;
int n;
ll co[200100];
int tp[200100];

void solve(int s, int e) {
    int i;
    ll chk[2] = {-1,-1};
    for (int j=1;j<=2;j++) {
        int las = s;
        for (i=s+1;i<=e;i++) {
            if ((tp[i]==j||tp[i]==0)&&(i!=e||las!=s)) {
                chk[j-1] = max(chk[j-1],co[i]-co[las]);
                las = i;
            }
        }
    }
    if (chk[0]<0&&chk[1]<0) {
        ans += co[e]-co[s];
        return;
    }
    sort(chk,chk+2);
    if (chk[0]<0) {
        ans += 2*(co[e]-co[s])-chk[1];
        return;
    }
    ans += 3*(co[e]-co[s])-max(co[e]-co[s],chk[0]+chk[1]);
}

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        char buf[3];
        scanf("%lld %s",&co[i],buf);
        if (buf[0]=='P') tp[i] = 0;
        else if(buf[0]=='B') tp[i] = 1;
        else tp[i] = 2;
    }
    bool is = 0;
    for (i=0;i<n;i++) {
        if (tp[i]==0) is = 1;
    }
    if (!is) {
        ll mini = 1e9+10, maxi = -1e9-10;
        for (i=0;i<n;i++) {
            if (tp[i]==1) {
                mini = min(mini,co[i]);
                maxi = max(maxi,co[i]);
            }
        }
        ans += max(maxi-mini,0LL);
        mini = 1e9+10, maxi = -1e9-10;
        for (i=0;i<n;i++) {
            if (tp[i]==2) {
                mini = min(mini,co[i]);
                maxi = max(maxi,co[i]);
            }
        }
        ans += max(maxi-mini,0LL);
        printf("%lld\n",ans);
        return 0;
    }
    ll mini = 1e9+10, maxi = -1e9-10;
    for (i=0;i<n;i++) {
        if (!tp[i]) {
            mini = min(mini,co[i]);
            maxi = max(maxi,co[i]);
        }
    }
    for (int j=1;j<3;j++) {
        for (i=0;i<n;i++) {
            if (tp[i]==j&&co[i]<mini) {
                ans += mini-co[i];
                break;
            }
        }
        for (i=n-1;i>=0;i--) {
            if (tp[i]==j&&co[i]>maxi) {
                ans += co[i]-maxi;
                break;
            }
        }
    }
    int p = -1, q = -1;
    for (i=0;i<n;i++){
        if (!tp[i]) {
            q = p;
            p = i;
            if (~q) {
                solve(q,p);
            }
        }
    }
    printf("%lld\n",ans);

    return 0;
}