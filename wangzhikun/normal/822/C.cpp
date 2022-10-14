#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=2e5+5;
typedef pair<int,int>pii;

vector<pii>v[N];//
vector<pii>rc[N];//
int    mp[N];
 
int main(){
    ios::sync_with_stdio(false); 
    int n,x;
    cin>>n>>x;    
    for(int i=1;i<=n;i++){
        int l,r,cost;
        cin>>l>>r>>cost;
        //l 
        rc[l].push_back(pii(r,cost));
    }
    int ans=2e9+1;
    //l 
    for(int l=1;l<=2e5;l++){
        for(int i=0;i<rc[l].size();i++){
            int r=rc[l][i].first;
            int cost=rc[l][i].second;
            int time=r-l+1;
            if(time>x)
                continue;
            //x, 
            if(mp[x-time]){ 
                ans=min(ans,mp[x-time]+cost);
            }
            // 
            v[r].push_back(pii(time,cost));    
        }
        //v[l],v[r]l2=l+1,r,, 
        for(int i=0;i<v[l].size();i++){
            int time=v[l][i].first;
            int cost=v[l][i].second;
            if(!mp[time]||mp[time]>cost)
                mp[time]=cost;    
        }
    }
    if(ans==2e9+1)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}