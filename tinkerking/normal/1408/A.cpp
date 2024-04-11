#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int N;
int a[110],b[110],c[110];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) scanf("%d",&a[i]);
        for (int i=1;i<=N;i++) scanf("%d",&b[i]);
        for (int i=1;i<=N;i++) scanf("%d",&c[i]);
        int last = -1e9;
        vector<int>ans;
        for (int i=1;i<N;i++) {
            if (a[i] != last) {ans.push_back(a[i]);last=a[i];continue;}
            if (b[i] != last) {ans.push_back(b[i]);last=b[i];continue;}
            if (c[i] != last) {ans.push_back(c[i]);last=c[i];continue;}
        }
        if (a[N] != last && a[N] != ans[0]) ans.push_back(a[N]);
        else if (b[N] != last && b[N] != ans[0]) ans.push_back(b[N]);
        else if (c[N] != last && c[N] != ans[0]) ans.push_back(c[N]);
        for (int i=0;i<N;i++) printf("%d%c",ans[i]," \n"[i==N-1]);
    }
}