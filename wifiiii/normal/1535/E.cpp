#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5+5;
int die[maxn], a[maxn], c[maxn];
int fa[maxn][20];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin >> q >> a[1] >> c[1];
    for(int i = 2; i <= q + 1; ++i) {
        int op;
        cin >> op;
        if(op == 1) {
            int p;
            cin >> p >> a[i] >> c[i];
            ++p;
            fa[i][0] = p;
            for(int j=1;j<=19;++j) fa[i][j]=fa[fa[i][j-1]][j-1];
        } else {
            int v, w;
            cin >> v >> w;
            ++v;
            ll ans1 = 0, ans2 = 0;
            while(w) {
                int x = v;
                for(int j=19;j>=0;--j) {
                    if(fa[x][j] && !die[fa[x][j]]) {
                        x=fa[x][j];
                    }
                }
                int p=min(w,a[x]);
                ans1+=p;
                ans2+=1ll*p*c[x];
                a[x]-=p;
                w-=p;
                if(!a[x]) die[x]=1;
                if(x==v) break;
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
    }
}