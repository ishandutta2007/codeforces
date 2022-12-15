#include <bits/stdc++.h>
using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed); int cnt, n, i, lo, hi; set<int> vs;
int qu(int x){
    printf("> %d\n",x);fflush(stdout);
    int r; scanf("%d",&r); return r;
}
vector<int> vec;
int main(){
    srand(time(0));
    scanf("%d",&n);
    lo = 0; hi = 1e9+1;
    while(lo < hi){
        int m = (lo+hi)/2; cnt++;
        if(qu(m-1)) lo=m+1;
        else hi=m;
    }
    lo--; vec.push_back(lo);
    for(i=1;i<=min(n,60-cnt);i++){
        int x = (1LL*rand()*rand())%n+1;
        while(vs.count(x)){
            x = (1LL*rand()*rand())%n+1;
        }
        vs.insert(x);
        printf("? %d\n",x); fflush(stdout);
        scanf("%d",&x); vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int d = vec[1]-vec[0];
    for(i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++)
            d = __gcd(abs(vec[j]-vec[i]),d);
    }
    printf("! %d %d\n",lo-(n-1)*d,d);
    return 0;
}