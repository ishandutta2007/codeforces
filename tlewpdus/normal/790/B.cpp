#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
ll res = 0;
vector<int> lis[200100];
struct al {
    int arr[5];
    al() {
        int i;
        for (i=0;i<5;i++) arr[i] = 0;
    }
    inline al operator + (const al &A) const {
        al B = al();
        int i;
        for (i=0;i<k;i++) B.arr[i] = arr[i]+A.arr[i];
        return B;
    }
};
al arr[200100];

al dfs(int here, int p, int d) {
    int i;
    al tmp = al();
    for (i=0;i<lis[here].size();i++) {
        int there = lis[here][i];
        if (there==p) continue;
        tmp = tmp + dfs(there,here,d+1);
    }
    tmp.arr[d%k]++;
    arr[here] = tmp;
    if (~p) {
        int sum = 0;
        for (i=0;i<k;i++) sum += tmp.arr[i];
        res += 1LL*sum*(n-sum);
    }
    return tmp;
}

void tdfs(int here, int p, int d, al pal) {
    int i, j;
    al tmp = al();
    for (i=1;i<k;i++) res += (k-i)*pal.arr[i];
    for (i=0;i<lis[here].size();i++) {
        int there = lis[here][i];
        if (there==p) continue;
        for (j=0;j<k;j++) tmp.arr[j] = pal.arr[(j+k-1)%k]-arr[there].arr[(j+d+k-1)%k];
        for (j=0;j<k;j++) tmp.arr[j] += arr[there].arr[(j+d+1)%k];
        tdfs(there,here,d+1,tmp);
    }
}

int main() {
    int i;
    scanf("%d%d",&n,&k);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        a--;b--;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    dfs(0,-1,0);
    res*=2;
    tdfs(0,-1,0,arr[0]);
    printf("%I64d\n",res/k/2);

    return 0;
}