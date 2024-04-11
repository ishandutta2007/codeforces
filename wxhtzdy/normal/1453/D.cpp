#include <bits/stdc++.h>
using namespace std;
long long f(long long n){
    long long res=4;
    while(n--)res*=2;
    return res-2;
}
int main(){
    vector<pair<long long,int>> all;
    for(int i=0;i<60;i++)all.push_back({f((long long)i),i});
    //for(auto c:all)printf("%lld %i\n",c.first,c.second);
    int t;scanf("%i",&t);
    while(t--){
        long long n;scanf("%lld",&n);
        if(n%2==1){
            printf("-1\n");
            continue;
        }
        vector<int> ans;
        int sum=0;
        while(n>0){
            int id=0;
            for(int i=0;i<(int)all.size();i++){
                if(all[i].first<=n)id=i;
            }
            sum+=all[id].second;
            n-=all[id].first;
            //printf("%i %i\n",all[id].second,id);
            ans.push_back(all[id].second);
        }
        printf("%i\n",sum+(int)ans.size());
        for(auto c:ans){
            printf("1 ");
            for(int j=0;j<c;j++)printf("0 ");
        }
        printf("\n");
    }
    return 0;
}