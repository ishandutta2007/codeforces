#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    map<int,long long> res;
    map<int,int> last,now;
    for(int i=0;i<n;i++){
        int x;scanf("%i",&x);
        now.clear();
        for(auto it:last){
            now[__gcd(it.first,x)]+=it.second;
        }
        now[x]++;
        swap(now,last);
        for(auto it:last){
            res[it.first]+=it.second;
        }
    }
    int q;scanf("%i",&q);
    while(q--){
        int x;scanf("%i",&x);
        printf("%lld\n",res[x]);
    }
    return 0;
}