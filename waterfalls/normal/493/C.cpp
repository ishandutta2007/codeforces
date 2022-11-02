#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int,int> > throws;
    int n,m,a;
    int throws1 = 0;
    int throws2 = 0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a);
        throws.push_back(pair<int,int>(a,1));
        throws1+=1;
    }
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        scanf("%d",&a);
        throws.push_back(pair<int,int>(a,2));
        throws2+=1;
    }
    throws.push_back(pair<int,int>(2*1e9,3));
    sort(throws.begin(),throws.end());
    long long int best1 = -1e18;
    long long int best2 = 0;
    int passed1 = 0;
    int passed2 = 0;
    for (int i=0;i<throws.size()+1;i++) {
        long long int score1 = 2LL*passed1+3LL*(throws1-passed1);
        long long int score2 = 2LL*passed2+3LL*(throws2-passed2);
        if ((i==0 || i==throws.size() || throws[i-1].first!=throws[i].first) && (score1-score2>best1-best2 || (score1-score2==best1-best2 && score1>best1))) {
            best1 = score1;
            best2 = score2;
        }
        if (i!=throws.size()) {
            if (throws[i].second==1) passed1+=1;
            else if (throws[i].second==2) passed2+=1;
        }
    }
    printf("%I64d:%I64d\n",best1,best2);

    return 0;
}