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
int siv[5010];
int deg[1010];
int knap[4][10010];
vector<int> pri;

int main() {
    for (int i=2;i<=3000;i++) {
        if (siv[i]) continue;
        pri.push_back(i);
        for (int j=i*2;j<=3000;j+=i) {
            siv[j] = 1;
        }
    }
    scanf("%d",&n);
    if (n<6) {
        int fl = 0, t = 0;
        for (int j=n;j<=n+n-3;j++) {
            if (!siv[j]) {
                fl=1;
                t = j;
                break;
            }
        }
        printf("%d\n",t);
        for (int i=1;i<=n;i++) {
            printf("%d %d\n",i,(i==n)?1:(i+1));
            deg[i]++;
            deg[(i==n)?1:(i+1)]++;
        }
        for (int i=3;i<3+t-n;i++) {
            printf("1 %d\n",i);
            deg[1]++;
            deg[i]++;
        }
        return 0;
    }
    knap[0][0] = 1;
    for (int i=1;i<=3;i++) {
        for (int j=1;j<10000;j++) {
            for (int k=0;k<pri.size();k++) {
                if (j>=pri[k]&&knap[i-1][j-pri[k]]) {
                    knap[i][j] = pri[k];
                }
            }
        }
    }
    int a = 0, b= 0, c = 0, m;
    for (m=n;m<=n+n-3;m++){
        if (siv[m]) continue;
        int v = m-n+4;
        if (knap[2][v]) {
            a=knap[2][v];
            b=knap[1][v-knap[2][v]];
            break;
        }
        int w = m-n+6;
        if (knap[3][w]) {
            a=knap[3][w];
            b=knap[2][w-knap[3][w]];
            c=w-a-b;
            break;
        }
    }
    printf("%d\n",m);
    for (int i=1;i<=n;i++) {
        printf("%d %d\n",i,(i==n)?1:(i+1));
        deg[i]++;
        deg[(i==n)?1:(i+1)]++;
    }
    if (c) {
        a-=2;b-=2;c-=2;
        if (a<b) swap(a,b);
        if (b<c) swap(b,c);
        if (a<b) swap(a,b);
        for (int i=4;i<4+a+b+c;i++) {
            int v = ((i<4+a)?1:((i<4+a+b)?2:3));
            printf("%d %d\n",v,i);
            deg[v]++; deg[i]++;
        }
    }
    else {
        a-=2;b-=2;
        if (a<b) swap(a,b);
        for (int i=3;i<3+a+b;i++) {
            int v = ((i<3+a)?1:2);
            printf("%d %d\n",v,i);
            deg[v]++; deg[i]++;
        }
    }

    return 0;
}