#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
int w[1000];
int h[1000];
int nums[2000];
int done[1000];
vector<pair<int,int> > todo;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.first>b.first;
}

int main() {
    scanf("%d",&n);
    int width = 0;
    int height = 0;
    for (int i=0;i<n;i++) {
        scanf("%d%d",&w[i],&h[i]);
        nums[2*i] = w[i];
        nums[2*i+1] = h[i];
        width+=w[i];
        height = max(height,h[i]);
    }
    int ans = width*height;
    for (int i=0;i<2*n;i++) {
        height = nums[i];
        int ok = 1;
        for (int j=0;j<n;j++) if (h[j]>height && w[j]>height) ok = 0;
        if (!ok) continue;
        int flipped = 0;
        for (int j=0;j<n;j++) if (h[j]>height) swap(h[j],w[j]), done[j] = 1, flipped+=1;
        todo.clear();
        for (int j=0;j<n;j++) if (w[j]<=height && w[j]>h[j]) todo.push_back(make_pair(w[j]-h[j],j));
        sort(todo.begin(),todo.end(),comp);
        int width = 0;
        for (int j=0;j<n;j++) width+=w[j];
        int where = 0;
        //if (2*flipped<=n)
        ans = min(ans,width*height);
        for (int j=0;j<todo.size();j++) {
            swap(h[todo[j].second],w[todo[j].second]);
            width-=todo[j].first;
            done[todo[j].second] = 1;
            flipped+=1;
            //if (2*flipped>n) break;
            ans = min(ans,width*height);
        }
        for (int j=0;j<n;j++) if (done[j]) swap(h[j],w[j]), done[j] = 0;
    }
    printf("%d\n",ans);

    return 0;
}