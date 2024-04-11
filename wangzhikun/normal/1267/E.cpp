#include <bits/stdc++.h>

using namespace std;

int po[110][110],n,m;
int ans[110],mnum = 1e9;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++)cin>>po[i][j];
    }
    for(int i=1;i<n;i++){
        vector< pair<int,int> > V;
        for(int j=0;j<m;j++){
            V.push_back(make_pair(po[j][n]-po[j][i],j));
        }
        sort(V.begin(),V.end());
        int cp = 0,cs = 0;
        while(cp<V.size()){
            if(cs+V[cp].first<=0){
                cs+=V[cp].first;
                cp++;
            }else{
                break;
            }
        }
        if(V.size()-cp<mnum){
            mnum = V.size()-cp;
            memset(ans,0,sizeof(ans));
            for(int j=0;j<cp;j++){
                ans[V[j].second] = 1;
            }
        }
    }
    
    cout<<mnum<<endl;
    int pre = 0;
    for(int i=0;i<m;i++){
        if(!ans[i]){
            if(pre)cout<<' ';
            cout<<i+1;
            pre = 1;
        }
    }
    cout<<endl;
    return 0;
}