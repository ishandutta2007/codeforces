#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair<int, int> pii;

const int N = 2e5 + 500;
const int K = 5;
const int OFF = (1 << K);
const int INF = 0x3f3f3f3f;

int A[N][K], n, k, qq;

struct KineskiDorucak{
    int mn[N * 4], mx[N * 4];
    void pull(int node){
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
    }
    void napravi(int node, int l, int r, int d){
        if(l == r){
            int val = 0;
            for(int i = 0;i < k;i++)
                if(d & (1 << i)) val += A[l][i];
                else val -= A[l][i];
            mn[node] = mx[node] = val;
            return;
        }
        int mid = l + r >> 1;
        napravi(node * 2, l, mid, d);
        napravi(node * 2 + 1, mid + 1, r, d);
        pull(node);
    }
    pii pitaj(int node, int l, int r, int ll, int rr){
        if(l > r || l > rr || r < ll)return {INF, -INF};
        if(ll <= l && r <= rr)return {mn[node], mx[node]};
        int mid = l + r >> 1;
        pii levo = pitaj(node * 2, l, mid, ll, rr);
        pii desno = pitaj(node * 2 + 1, mid + 1, r, ll, rr);
        pii ret = {min(levo.X, desno.X), max(levo.Y, desno.Y)};
        return ret;
    }
    void namesti(int node, int l, int r, int pos, int d){
        if(l == r){
            int val = 0;
            for(int i = 0;i < k;i++)
                if(d & (1 << i)) val += A[l][i];
                else val -= A[l][i];
            mn[node] = mx[node] = val;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid)namesti(node * 2, l, mid, pos, d);
        else namesti(node * 2 + 1, mid + 1, r, pos, d);
        pull(node);
    }
} ST[OFF];

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= n;i++)
        for(int j = 0;j < k;j++)
            scanf("%d", &A[i][j]);
    for(int j = 0;j < OFF;j++)
        ST[j].napravi(1, 1, n, j);
    scanf("%d", &qq);
    while(qq--){
        int type; scanf("%d", &type);
        if(type == 1){
            int i; scanf("%d", &i);
            for(int j = 0;j < k;j++)
                scanf("%d", &A[i][j]);
            for(int j = 0;j < OFF;j++)
                ST[j].namesti(1, 1, n, i, j);
        }else{
            int l, r; scanf("%d%d", &l, &r);
            int answer = -INF;
            for(int i = 0;i < (1 << k);i++){
                pii sundjer = ST[i].pitaj(1, 1, n, l, r);
                answer = max(answer, sundjer.Y - sundjer.X);
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}