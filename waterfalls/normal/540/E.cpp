#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

class FT {
private:
    int size;
    int ft[200013];
    int sumto(int a) {
        int ans = 0;
        while (a>0) {
            ans+=ft[a];
            a-=a&(-a);
        }
        return ans;
    }
public:
    FT(int s=0) {
        size = s;
        fill(ft,ft+size+1,0);
    }
    void update(int x, int val) {
        while (x<=size) {
            ft[x]+=val;
            x+=x&(-x);
        }
    }
    int query(int a, int b) { return sumto(b)-sumto(a-1); }
};

int n;
int a[100013];
int b[100013];
set<int> nums;
map<int,int> id;
int ret[200013];
vector<int> cur;
FT tree;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]), nums.insert(a[i]), nums.insert(b[i]);
    for (set<int>::iterator it=nums.begin();it!=nums.end();++it) id[*it] = id.size()-1, ret[id.size()] = *it;
    for (int i=1;i<=nums.size();i++) cur.push_back(i);
    for (int i=0;i<n;i++) swap(cur[id[a[i]]],cur[id[b[i]]]);
    tree = FT(nums.size());
    long long ans = 0;
    for (int i=0;i<nums.size();i++) {
        ans+=tree.query(cur[i],nums.size());
        tree.update(cur[i],1);
    }
    for (int i=0;i<nums.size();i++) ans+=abs(ret[cur[i]]-ret[i+1])+1-tree.query(min(i+1,cur[i]),max(i+1,cur[i]));
    printf("%I64d\n",ans);

    return 0;
}