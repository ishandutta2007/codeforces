#include <bits/stdc++.h>
using namespace std;
int vals[300001][8];
int n,m;
pair<int,int> simulate(int k){
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i] = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(vals[i][j]>=k)
                temp[i]+=(1<<j);
    vector<int> bit[256];
    pair<int,int> ans = {-1,-1};
    for(int i=0;i<n;i++)
        bit[temp[i]].push_back(i);
    for(int i=0;i<256;i++)
        for(int j=0;j<256;j++)
            if((i|j)==(1<<m)-1){
                if(i==j){
                    if(bit[i].size()==1)
                        return {bit[i][0],bit[i][0]};
                    else if(bit[i].size()>=2)
                        return {bit[i][0],bit[i][1]};
                }
                else
                    if(bit[i].size()>=1 && bit[j].size()>=1)
                        return {bit[i][0],bit[j][0]};
            }
    return {-1,-1};
}
bool works(int k){
    pair<int,int> x = simulate(k);
    return x.first>=0 && x.second>=0;
}
int binarySearch(int lo,int hi){
    int mid = (lo+hi)/2;
    if(works(mid)){
        if(!works(mid+1))
            return mid;       
        return binarySearch(mid+1,hi);
    }
    return binarySearch(lo,mid-1);


}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&vals[i][j]);
    int x = binarySearch(0,1e9);
    auto ans = simulate(x);
    cout << ans.first+1 << " " << ans.second+1 << endl;
    
    
}