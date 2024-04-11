#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class FT {
private:
    int ft[200005];
    int size;
public:
    FT(int s=0) {
        fill(ft,ft+s+1,0);
        size = s;
    }
    void update(int ind, int val) {
        ind+=1;
        while (ind<=size) {
            ft[ind]+=val;
            ind+=ind&(-ind);
        }
    }
    int sumTo(int ind) {
        ind+=1;
        int sum = 0;
        while (ind>0) {
            sum+=ft[ind];
            ind-=ind&(-ind);
        }
        return sum;
    }
};

int n;
FT tree;
vector<int> first;
vector<int> id1;
vector<int> second;
vector<int> id2;
vector<int> next;

void findNum(vector<int>& from, vector<int>& dest) {
    tree = FT(n);
    for (int i=0;i<n;i++) {
        dest.push_back(from[i]-tree.sumTo(from[i]));
        tree.update(from[i],1);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<2*n;i++) {
        int a;
        scanf("%d",&a);
        if (i<n) first.push_back(a);
        else second.push_back(a);
    }
    findNum(first,id1); findNum(second,id2);
    for (int i=0;i<n;i++) next.push_back(0);
    for (int i=n-1;i>=0;i--) {
        next[i]+=id1[i]+id2[i];
        if (next[i]>=n-i) {
            if (i>0) next[i-1]+=next[i]/(n-i);
            next[i]%=(n-i);
        }
    }
    tree = FT(n);
    for (int i=0;i<n;i++) {
        int low = -1;
        int high = n-1;
        while (high-low>1) {
            int mid = (low+high)/2;
            if (mid-tree.sumTo(mid)>=next[i]) high = mid;
            else low = mid;
        }
        printf("%d ",high);
        tree.update(high,1);
    }
    printf("\n");

    return 0;
}