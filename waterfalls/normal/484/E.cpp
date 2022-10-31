#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class ST {
private:
    int l[400013];
    int m[400013];
    int r[400013];
    int size;
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    pair<int,pair<int,int> > queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return make_pair(0,make_pair(0,0));
        if (L>=a && R<=b) return make_pair(m[w],make_pair(l[w],r[w]));
        pair<int,pair<int,int> > lC = queryI(left(w),L,(L+R)/2,a,b);
        pair<int,pair<int,int> > rC = queryI(right(w),(L+R)/2+1,R,a,b);
        pair<int,pair<int,int> > re;
        re.first = max(max(lC.first,rC.first),lC.second.second+rC.second.first);
        re.second.first = (lC.second.first==(L+R)/2-L+1) ? lC.second.first+rC.second.first : lC.second.first;
        re.second.second = (rC.second.second==R-(L+R)/2) ? rC.second.second+lC.second.second : rC.second.second;
        return re;
    }
    void updateI(int w, int L, int R, int a) {
        if (a>R || a<L) return;
        if (L==R) {
            l[w] = 1;
            m[w] = 1;
            r[w] = 1;
        } else {
            updateI(left(w),L,(L+R)/2,a);
            updateI(right(w),(L+R)/2+1,R,a);
            l[w] = (l[left(w)]==(L+R)/2-L+1) ? l[left(w)]+l[right(w)] : l[left(w)];
            m[w] = max(max(m[left(w)],m[right(w)]),r[left(w)]+l[right(w)]);
            r[w] = (r[right(w)]==R-(L+R)/2) ? r[right(w)]+r[left(w)] : r[right(w)];
        }
    }

public:
    ST(int s=0) {
        fill(l,l+4*s,0);
        fill(m,m+4*s,0);
        fill(r,r+4*s,0);
        size = s;
    }
    int query(int a, int b) { return queryI(1,0,size-1,a,b).first; }
    void update(int a) { updateI(1,0,size-1,a); }
};

int n,m;
int h[100013];
pair<pair<int,int>,int> queries[100013];
int low[100013];
int high[100013];
vector<int> mid[100013];
vector<pair<int,int> > heights;
ST tree;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&h[i]),heights.push_back(make_pair(-h[i],i));
    sort(heights.begin(),heights.end());
    scanf("%d",&m);
    for (int i=0;i<m;i++) scanf("%d%d%d",&queries[i].first.first,&queries[i].first.second,&queries[i].second);
    for (int i=0;i<m;i++) queries[i].first.first-=1, queries[i].first.second-=1;
    for (int i=0;i<m;i++) low[i] = -1, high[i] = n-1;
    for (int r=0;r<30;r++) {
        for (int i=0;i<m;i++) mid[(low[i]+high[i]+1)/2].push_back(i);
        tree = ST(n);
        for (int i=0;i<n;i++) {
            tree.update(heights[i].second);
            for (int j=0;j<mid[i].size();j++) {
                if (tree.query(queries[mid[i][j]].first.first,queries[mid[i][j]].first.second)>=queries[mid[i][j]].second) {
                    high[mid[i][j]] = i;
                } else low[mid[i][j]] = i;
            }
            mid[i].clear();
        }
    }
    for (int i=0;i<m;i++) printf("%d\n",-heights[high[i]].first);

    return 0;
}