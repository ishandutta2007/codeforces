#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
vector<int> cur;

int main() {
    scanf("%d%d",&n,&k);
    int ans = 0;
    for (int i=0;i<k;i++) {
        cur.clear();
        int num;
        scanf("%d",&num);
        for (int j=0;j<num;j++) {
            int x;
            scanf("%d",&x);
            cur.push_back(x);
        }
        if (cur[0]!=1) {
            ans+=num-1+num;
        } else {
            int l = 1;
            while (l<num && cur[l]==cur[l-1]+1) l+=1;
            ans+=num-l+num-l;
        }
    }
    printf("%d\n",ans);

    return 0;
}