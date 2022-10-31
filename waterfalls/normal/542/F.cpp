#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n,T;
priority_queue<pair<int,int> > tasks;

int main() {
    scanf("%d%d",&n,&T);
    for (int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        tasks.push(make_pair(T-a,b));
    }
    int ans = 0;
    while (tasks.size()>0) {
        pair<int,int> a = tasks.top();
        tasks.pop();
        if (a.first==0) ans = max(ans,a.second);
        else if (tasks.size()>0 && tasks.top().first==a.first) {
            pair<int,int> b = tasks.top();
            tasks.pop();
            tasks.push(make_pair(a.first-1,a.second+b.second));
        } else tasks.push(make_pair(a.first-1,a.second));
    }
    printf("%d\n",ans);
}