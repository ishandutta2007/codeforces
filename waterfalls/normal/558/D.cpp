#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int h,Q;
map<long long,int> val;
vector<long long> has;
vector<int> nums;

long long maxn;

long long lc(long long x) {
    while (x*2<=maxn) x = x*2;
    return x;
}

long long rc(long long x) {
    while (x*2+1<=maxn) x = x*2+1;
    return x;
}

int main() {
    scanf("%d%d",&h,&Q);
    if (Q==0) {
        if (h==1) printf("1\n");
        else printf("Data not sufficient!\n");
        return 0;
    }
    maxn = (1LL<<h)-1;
    for (int q=0;q<Q;q++) {
        int i;
        long long L,R;
        int ans;
        scanf("%d%I64d%I64d%d",&i,&L,&R,&ans);
        if (ans) {
            val[lc(L)]+=1;
            val[rc(R)+1]-=1;
        } else {
            val[(1LL<<(h-1))]+=1;
            val[lc(L)]-=1;
            val[rc(R)+1]+=1;
            val[maxn+1]-=1;
        }
    }
    for (auto& it: val) {
        has.push_back(it.first);
        nums.push_back(it.second);
    }
    for (int i=1;i<nums.size();i++) nums[i]+=nums[i-1];
    int found = 0;
    int where = -1;
    for (int i=0;i<nums.size();i++) if (nums[i]==Q) found+=1, where = i;
    if (found>1) printf("Data not sufficient!\n");
    else if (found==1) {
        if (has[where]==maxn || val.count(has[where]+1)) printf("%I64d\n",has[where]);
        else printf("Data not sufficient!\n");
    } else printf("Game cheated!\n");

    return 0;
}