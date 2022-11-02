#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int n;
int a[MAXN], b[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++){
        b[i] = a[i] - a[i - 1];
    }
    vector<int> u;
    for (int i = 1; i <= n; i++){
        int  flag = 1;
        for (int j = 1; j + i <= n; j++){
            if (b[j] != b[j + i]){
                flag = 0;
                break;
            }
        }
        if (flag)
            u.push_back(i);
    }
    printf("%u\n", u.size());
    for (int i = 0; i < u.size(); i++)
        printf("%d%c", u[i], " \n"[i + 1 == u.size()]);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}