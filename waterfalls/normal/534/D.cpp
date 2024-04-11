#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int n;
int a[200013];
deque<int> has[200013];
multiset<int> ordered;
multiset<int> mod3[3];
vector<int> toPrint;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) has[a[i]].push_back(i+1), ordered.insert(a[i]), mod3[a[i]%3].insert(a[i]);
    int where = 0;
    if (has[0].size()==0) {
        printf("Impossible\n");
        return 0;
    }
    toPrint.push_back(has[0].front());
    has[0].pop_front();
    ordered.erase(ordered.find(0));
    mod3[0%3].erase(mod3[0%3].find(0));
    while (true) {
        if (ordered.size()==0) break;
        if (where>=2 && has[where-2].size()>0 && has[where-1].size()>0 && has[where].size()>0) where-=2;
        else if (has[where+1].size()>0) where+=1;
        else {
            if (*(--ordered.end())>where) break;
            if (mod3[(where+1)%3].size()==0) break;
            where = *(--mod3[(where+1)%3].end());
        }
        toPrint.push_back(has[where].front());
        has[where].pop_front();
        ordered.erase(ordered.find(where));
        mod3[where%3].erase(mod3[where%3].find(where));
    }
    if (toPrint.size()==n) {
        printf("Possible\n");
        for (int i=0;i<n;i++) printf("%d ",toPrint[i]);
        printf("\n");
    } else printf("Impossible\n");

    return 0;
}