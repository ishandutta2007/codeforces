#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n,m;
vector<vector<int> > stuff;
int who[100000];
set<vector<int> > actors;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        stuff.push_back(vector<int>({a,-b,0,i}));
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++) {
        int c,d,k;
        scanf("%d%d%d",&c,&d,&k);
        stuff.push_back(vector<int>({c,-d,-i,k}));
    }
    sort(stuff.begin(),stuff.end());
    int ok = 1;
    for (int i=0;i<stuff.size() && ok;i++) {
        vector<int> next = stuff[i];
        if (-next[2]) actors.insert(vector<int>({-next[1],next[0],next[3],-next[2]}));
        else {
             set<vector<int> >::iterator which = actors.lower_bound(vector<int>({-next[1],0,0}));
             if (which==actors.end()) ok = false;
             else {
                vector<int> actor = *which;
                who[next[3]] = actor[3];
                actors.erase(which);
                if (actor[2]>1) actors.insert(vector<int>({actor[0],actor[1],actor[2]-1,actor[3]}));
             }
        }
    }
    if (ok) {
        printf("YES\n");
        for (int i=0;i<n;i++) printf("%d ",who[i]);
        printf("\n");
    } else printf("NO\n");

    return 0;
}