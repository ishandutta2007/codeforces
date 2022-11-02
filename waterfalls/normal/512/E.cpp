#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
set<pair<int,int> > diagonals;
set<pair<int,int> > finish;
vector<pair<int,int> > toPrint;
vector<int> has;
set<int> has2;
int before[1000];
int after[1000];

void change(int a, int b, int c, int d) {
    diagonals.erase(make_pair(a,c));
    diagonals.erase(make_pair(c,a));
    diagonals.insert(make_pair(b,d));
    diagonals.insert(make_pair(d,b));
    toPrint.push_back(make_pair(a+1,c+1));
}

void solve() {
    if (has.size()<4) return;
    int num = has.size();
    int done = 0;
    for (int i=0;i<num && !done;i++) {
        int one = diagonals.count(make_pair(has[(i+num-1)%num],has[(i+1)%num]));
        int two = finish.count(make_pair(has[(i+num-1)%num],has[(i+1)%num]));
        if (one && two) {
            has2.erase(has[i]);
            has.erase(has.begin()+i);
            done = 1;
            solve();
        } else if (two && !one) {
            vector<int> others;
            for (set<pair<int,int> >::iterator it=diagonals.begin();it!=diagonals.end();it++) if (it->first==has[i] && has2.count(it->second) && it->second!=has[(i+1)%num] && it->second!=has[(i+num-1)%num]) others.push_back(it->second);
            for (int j=0;j<others.size();j++) if (others[j]<has[i]) others[j]+=n;
            sort(others.begin(),others.end());
            others.insert(others.begin(),has[(i+1)%num]);
            for (int j=0;j<others.size();j++) if (others[j]>=n) others[j]-=n;
            others.push_back(has[(i+num-1)%num]);
            vector<int> toRandom;
            for (int j=1;j<others.size()-1;j++) {
                before[j] = j-1;
                after[j] = j+1;
                toRandom.push_back(j);
            }
            random_shuffle(toRandom.begin(),toRandom.end());
            for (int j=0;j<toRandom.size();j++) {
                int pick = toRandom[j];
                change(has[i],others[before[pick]],others[pick],others[after[pick]]);
                before[after[pick]] = before[pick];
                after[before[pick]] = after[pick];
            }
            has2.erase(has[i]);
            has.erase(has.begin()+i);
            done = 1;
            solve();
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n-3;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        diagonals.insert(make_pair(a-1,b-1));
        diagonals.insert(make_pair(b-1,a-1));
    }
    for (int i=0;i<n-3;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        finish.insert(make_pair(a-1,b-1));
        finish.insert(make_pair(b-1,a-1));
    }
    for (int i=0;i<n;i++) {
        has.push_back(i);
        has2.insert(i);
    }
    solve();
    printf("%d\n",toPrint.size());
    for (int i=0;i<toPrint.size();i++) printf("%d %d\n",toPrint[i].first,toPrint[i].second);

    return 0;
}