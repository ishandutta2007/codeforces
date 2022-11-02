#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int h[200013];
int p[200013];
int s[200013];
bool on[200013];
pair<int,int> event[200013];
int ans[200013];

int find(int x) { return p[x]==x ? x : p[x] = find(p[x]); }
void merge(int a, int b) { a = find(a); b = find(b); if (a>b) swap(a,b); p[a] = b; s[b]+=s[a]; }

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) p[i] = i, s[i] = 1, scanf("%d",&h[i]);
    for (int i=1;i<=n;i++) event[i] = make_pair(-h[i],i);
    sort(event+1,event+n+1);
    for (int i=1;i<=n;i++) {
        int x = event[i].second;
        on[x] = 1;
        if (on[x-1]) merge(x,x-1);
        if (on[x+1]) merge(x,x+1);
        ans[s[find(x)]] = max(ans[s[find(x)]],h[x]);
    }
    for (int i=n-1;i>0;i--) ans[i] = max(ans[i],ans[i+1]);
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);

    return 0;
}