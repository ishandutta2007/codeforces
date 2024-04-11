#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

const int MN = 200000 + 5;
const int TN = 1<<18;

int N, Q;
int A[MN];

int T[2*TN];
vector<int> pos[MN];

void update(int n){
    for(n += TN; n > 0; n>>=1){
        T[n]++;
    }
}

int getSum(int l, int r){
    int s = 0;
    for(l += TN, r += TN; l <= r; l>>=1, r>>=1){
        if(l&1) {
            s += T[l++];
        }
        if(!(r&1)) {
            s += T[r--];
        }
    }
    return s;
}

int main(){
    scanf("%d%d",&N,&Q);

    vector<int> izeroes;
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
        if(A[i] > 0) {
            pos[A[i]].push_back(i);
        }
        else {
            izeroes.push_back(i);
        }
    }
    if(pos[Q].size() == 0){
        if(izeroes.size() == 0){
            puts("NO");
            return 0;
        }
        else {
            pos[Q].push_back(izeroes.back());
            izeroes.pop_back();
            A[pos[Q].front()] = Q;
        }
    }
    for(int p: izeroes)
        update(p);

    for(int i=Q;i>=1;i--){
        sort(pos[i].begin(), pos[i].end());
        if(pos[i].size() == 0)continue;

        // printf("s %d %d\n", pos[i].front(), pos[i].back());
        int zero = getSum(pos[i].front(), pos[i].back());
        // printf("%d %d\n", i, zero);
        if(zero + pos[i].size() == pos[i].back() - pos[i].front() + 1) {
            for(int p: pos[i]) {
                update(p);
                // printf("c %d\n", p);
            }
        }
        else {
            puts("NO");
            // printf("%d\n",i);
            return 0;
        }
    }
    for(int i=1;i<N;i++){
        if(A[i] == 0) A[i] = A[i-1];
    }
    for(int i=N-2;i>=0;i--){
        if(A[i] == 0) A[i] = A[i+1];
    }
    if(A[0] == 0){
        for(int i=0;i<N;i++)A[i] = Q;
    }
    puts("YES");
    for(int i=0;i<N;i++)
        printf("%d ", A[i]);
    return 0;
}