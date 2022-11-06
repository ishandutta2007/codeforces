#include<cstdio>
#include<algorithm>
using namespace std;
struct info{
    int i, c;
    bool operator<(const info &A) const {return i<A.i;}
};
info in[200010];
int main() {
    int n, m, N = 0, a, b;
    long long ans = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &in[N].i, &in[N].c);
        N++;
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &in[N].i, &in[N].c);
        N++;
    }
    sort(in, in+N);
    for(int i=0, j; i<N; i=j){
        int max = 0;
        for(j=i; j<N && in[i].i == in[j].i; j++){
            if(max < in[j].c) max = in[j].c;
        }
        ans += max;
    }
    printf("%lld\n", ans);
    return 0;
}