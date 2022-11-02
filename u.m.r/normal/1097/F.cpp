#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;
const int MM = 1e9 + 7;

namespace umi {
    const int N = 7777;
    bool not_prime[N];
    int prime[N];
    int mu[N];
    int tot;
    void Mu(int n){
        int i,j;
        mu[1]=1;
        for(i=2;i<=n;i++){
            if(!not_prime[i]){
                prime[++tot]=i;
                mu[i]=-1;
            }
            for(j=1;prime[j]*i<=n;j++){
                not_prime[prime[j]*i]=1;
                if(i%prime[j]==0){
                    mu[prime[j]*i]=0;
                    break;
                }
                mu[prime[j]*i]=-mu[i];
            }
        }
    } 
}

ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

bitset<7040> a[MAXN]; 
bitset<7040> eli[7040];
vector<int> fac[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    int n, Q;
    umi::Mu(7007);
    for (int i = 1; i < 7007; i++) {
        int j = 1;
        while (j * j < i) {
            if (i % j == 0) {
                fac[i].push_back(j);
                fac[i].push_back(i / j);
            }
            j++;
        }
        if (j * j == i)
            fac[i].push_back(j);
        sort(fac[i].begin(), fac[i].end());
    }
    /*
    for (int i = 1; i <= 16; i++) {
        cout << i << ' ' << umi::mu[i] << " :   ";
        for (auto &x : fac[i]) cout << x << ' '; cout << endl;
    }*/
    for (int i = 1; i <= 7000; i++) {
        for (int j = i, k = 1; j <= 7000; j += i, k++)
            if (umi::mu[k])
                eli[i].set(j);
    }
    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= Q; i++) {
        int tp, x, y, z;
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d%d", &x, &y);
            a[x].reset();
            for (auto &z : fac[y])
                a[x].flip(z);
        }
        else if (tp == 2) {
            scanf("%d%d%d", &x, &y, &z);
            a[x] = a[y] ^ a[z];
        }
        else if (tp == 3) {
            scanf("%d%d%d", &x, &y, &z);
            a[x] = a[y] & a[z];
        }
        else {
            scanf("%d%d", &x, &y);
            int ans = (eli[y] & a[x]).count();
            ans %= 2;
            printf("%d", ans);
        }
        /*
        cout << "============" << endl;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 6; k++)
                cout << a[j][k]; cout << endl;
        }*/
    }
    puts("");
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}