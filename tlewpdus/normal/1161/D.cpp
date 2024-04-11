#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
char str[1010];
int arr[1010];
int po[2010];

int par[1010];
vector<int> lis[1010];

int comp;
void init() {
    int i;
    for (i=0;i<n;i++)par[i] = i;
}
int fin(int a) {
    return par[a] = (par[a]==a?a:fin(par[a]));
}
void uni(int a, int b) {
    a =fin(a); b=fin(b);
    if (a==b) return;
    comp--;
    par[a]=b;
}

int main() {
    int i;

    scanf("%s",str);
    n = strlen(str);
    if (str[n-1]=='1') {
        puts("0");
        return 0;
    }
    str[n-1]='0';
    ll cnt = 1;
    po[0] = 1;
    for (i=1;i<=2*n;i++)po[i]=po[i-1]*2%MOD;
    for (i=0;i<n;i++) if (str[i]=='?') cnt=cnt*2%MOD;
    ll res = 0;
    for (i=n-1;i>=1;i--) {
        init();
        comp=n+i;
        int j;
        for (j=0;j<n;j++) lis[j].clear();
        for (j=0;j<n;j++) {
            uni(j,n-1-j);
        }
        for (j=0;j<i;j++) {
            uni(j,i-1-j);
        }
        for (j=0;j<n;j++) {
            lis[fin(j)].push_back(j);
        }
        vector<int> vec;
        for (j=i;j<n;j++) {
            vec.push_back(fin(j));
        }
        sort(vec.begin(),vec.end());
        ll mul = 1, half = (MOD+1)/2;
        for (j=0;j+1<vec.size();j++) {
            if (vec[j]==vec[j+1]) {
                int c = 0, x = 0;
                for (int &v :lis[vec[j]]) {
                    if (str[v]=='?') c=1;
                    else x^=(str[v]-'0');
                }
                if (!c&&x) {
                    mul = 0;
                }
                if (c) mul=mul*half%MOD;
            }
        }
        res += mul*cnt%MOD;
    }
    printf("%lld\n",res%MOD);

    return 0;
}