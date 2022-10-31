#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define LIMIT 200013
int bt[LIMIT];
int N;

struct Stuff {
int a,b,c,d,e;
};

vector<Stuff> segments(200013); // (L_i, R_i, input order, endpoint order, ans)
int ans[200013];

bool cmpStart(Stuff v1, Stuff v2) {
    return v1.a < v2.a;
}
bool cmpEnd(Stuff v1, Stuff v2) {
    return v1.b < v2.b;
}
void update(int i, int v) {
    while (i <= N+1) {
        bt[i] += v;
        i += (-i) & i;
    }
}
int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += bt[i];
        i -= (-i) & i;
    }
    return sum;
}
int main() {
scanf("%d",&N);
    for (int i = 0; i < N; i ++) {
scanf("%d%d",&segments[i].a,&segments[i].b);
        segments[i].c = i;
    }
    sort(segments.begin(), segments.begin() + N, cmpEnd);
    for (int i = 0; i < N; i ++) {
        segments[i].b = i+1;
        update(i+1, 1);
    }
    sort(segments.begin(), segments.begin() + N, cmpStart);
    for (int i = 0; i < N; i ++) {
        ans[segments[i].c] = query(segments[i].b) - 1;
        update(segments[i].b, -1);
    }
    for (int i = 0; i < N; i ++) {
printf("%d\n",ans[i]);
    }
}