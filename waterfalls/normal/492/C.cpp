#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,r,avg;
    scanf("%d%d%d",&n,&r,&avg);
    long long need = (long long) avg*n;
    vector<pair<int,int> > tests;
    long long tot = 0;
    for (int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        tot+=a;
        tests.push_back(pair<int,int>(b,a));
    }
    sort(tests.begin(),tests.end());
    long long essays = 0;
    int where = 0;
    while (tot<need) {
        long long write = min((long long) r-tests[where].second,need-tot);
        tot+=write;
        essays+=tests[where].first*write;
        where+=1;
    }
    printf("%I64d\n",essays);

    return 0;
}