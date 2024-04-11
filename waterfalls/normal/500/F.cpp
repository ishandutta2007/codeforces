#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Item {
    int c,h,t;
};

class Knapstack {
private:
    vector<vector<int> > one;
    vector<Item> onone;
    vector<vector<int> > two;

    void add(vector<vector<int> >& dp, Item it) {
        vector<int> n;
        for (int i=0;i<4013;i++) {
            n.push_back(dp.back()[i]);
            if (i>=it.c) n[i] = max(n[i],dp.back()[i-it.c]+it.h);
        }
        dp.push_back(n);
    }
    void move() {
        while (one.size()>1) {
            add(two,onone.back());
            onone.pop_back();
            one.pop_back();
        }
    }
public:
    Knapstack() {
        one.push_back(vector<int>(4013));
        two.push_back(vector<int>(4013));
    }
    void push(Item it) {
        add(one,it);
        onone.push_back(it);
    }
    void pop() {
        if (two.size()==1) move();
        two.pop_back();
    }
    int query(int b) {
        int ans = 0;
        for (int u=0;u<=b;u++) ans = max(ans,one.back()[u]+two.back()[b-u]);
        return ans;
    }
};

int n,p,q;
Item items[4013];
vector<Item> on[20013];
int off[20013];
vector<pair<int,int> > queries[20013];
int ans[20013];
Knapstack k;

int main() {
    scanf("%d%d",&n,&p);
    for (int i=0;i<n;i++) {
        int c,h,t;
        scanf("%d%d%d",&c,&h,&t);
        items[i] = {c,h,t};
    }
    for (int i=0;i<n;i++) {
        on[items[i].t].push_back(items[i]);
        off[items[i].t+p]+=1;
    }
    scanf("%d",&q);
    for (int Q=0;Q<q;Q++) {
        int a,b;
        scanf("%d%d",&a,&b);
        queries[a].push_back(make_pair(b,Q));
    }
    for (int t=0;t<20013;t++) {
        for (int i=0;i<off[t];i++) k.pop();
        for (Item it: on[t]) k.push(it);
        for (pair<int,int> query: queries[t]) {
            ans[query.second] = k.query(query.first);
        }
    }
    for (int i=0;i<q;i++) printf("%d\n",ans[i]);

    return 0;
}