#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%i %i",&n,&k);
    vector<pair<int,int>> v;
    for(int i=0,a;i<n;i++){
        scanf("%i",&a);
        v.push_back({a,i+1});
    }
    sort(v.begin(),v.end());
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(k>=v[i].first){
            ans.push_back(v[i].second);
            k-=v[i].first;
        }
    }
    printf("%i\n",(int)ans.size());
    for(int c:ans)printf("%i ",c);
    return 0;
}