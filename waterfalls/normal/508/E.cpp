#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
pair<int,int> open[600];
vector<char> ans;
vector<int> ends;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        open[i] = make_pair(a,b);
    }
    ends.push_back(0);
    int ok = 1;
    for (int i=n-1;i>=0 && ok;i--) {
        int done = 0;
        for (int j=0;j<ends.size() && !done;j++) {
            if (ends[j]+1>=open[i].first && ends[j]+1<=open[i].second) {
                ans.insert(ans.begin()+ends[j],')');
                ans.insert(ans.begin(),'(');
                if (ends[j]!=0) for (int k=0;k<j;k++) ends.erase(ends.begin());
                ends.insert(ends.begin(),0);
                for (int k=1;k<ends.size();k++) ends[k]+=2;
                done = 1;
            }
        }
        if (!done) ok = 0;
    }
    if (!ok) printf("IMPOSSIBLE");
    else for (int i=0;i<ans.size();i++) printf("%c",ans[i]);
    printf("\n");
}