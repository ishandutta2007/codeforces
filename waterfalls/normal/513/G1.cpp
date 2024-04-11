#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;

double solve(vector<int> p,int done) {
    if (done==k) {
        int num = 0;
        for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (p[i]>p[j]) num+=1;
        return num;
    }
    double ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            vector<int> next = p;
            for (int k=i;k<=(i+j)/2;k++) swap(next[k],next[i+j-k]);
            ans+=solve(next,done+1)/(n*(n+1)/2);
        }
    }
    return ans;
}

int main() {
    scanf("%d%d",&n,&k);
    vector<int> p;
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        p.push_back(a);
    }
    printf("%1.12f\n",solve(p,0));

    return 0;
}