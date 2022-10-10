#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int BLOCKSZ = 300;

struct query {

    int l, r;
    int id;

    bool operator < (const query &A){
        if(l/BLOCKSZ == A.l/BLOCKSZ) return r < A.r;
        return l/BLOCKSZ < A.l/BLOCKSZ;
    }
};

const int LIM = (1<<22);
ll freq[LIM] = {}, ans = 0;
int K, pre[LIM];

void add(int p){
    ans += freq[pre[p]^K];
    freq[pre[p]]++;
}

void remove(int p){
    freq[pre[p]]--;
    ans -= freq[pre[p]^K];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q >> K;

    pre[0] = 0;
    for(int i=1; i<=N; i++){
        cin >> pre[i];
        pre[i] ^= pre[i-1];
    }

    vector<query> q(Q);
    vector<ll> resp(Q);

    for(int i=0; i<Q; i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].id = i;
    }
    sort(q.begin(), q.end());

    for(int i=q[0].l; i<=q[0].r; i++){
        add(i);
    }

    int j=q[0].l, k=q[0].r;
    for(auto qu: q){
        
        while(j>qu.l){
            j--;
            add(j);
        }

        while(k<qu.r){
            k++;
            add(k);
        }

        while(j<qu.l){
            remove(j);
            j++;
        }

        while(k>qu.r){
            remove(k);
            k--;
        }

        resp[qu.id] = ans;
    }

    for(auto r: resp){
        cout << r << '\n';
    }

    return 0;
}