#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
using namespace std;

const int ML = 1e4+4;
int T, N, i, x, ans2; double ans;
vector<int> vec;
bitset<ML> msk;

int main(){
    for(scanf("%d",&T);T;T--){
        msk.reset(); ans=1e18;
        for(scanf("%d",&N),i=1;i<=N;i++){
            scanf("%d",&x); msk[x].flip();
            if(!msk[x]) vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        for(i=0;i<vec.size()-1;i++){
            if(sq((double)2.0*(vec[i]+vec[i+1]))/(double)(vec[i]*vec[i+1])<ans){
                ans = sq((double)2.0*(vec[i]+vec[i+1]))/(double)(vec[i]*vec[i+1]);
                ans2 = i;
            }
        }
        printf("%d %d %d %d\n",vec[ans2],vec[ans2],vec[ans2+1],vec[ans2+1]);
        vec.clear();
    }
    return 0;
}