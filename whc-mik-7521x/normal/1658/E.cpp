#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int dp[N][N],n,k,mp[N][N];
struct node{
    int val,x,y;
    int fx(){return x+y;}
    int fy(){return x-y;}
    bool operator<(const node b)const{
        return val>b.val;
    }
};
vector<node>v;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++){
            int x;
            scanf("%d",&x);
            v.push_back({x,i,o});
        }
    }
    stable_sort(v.begin(),v.end());
    int mxx,mix,mxy,miy;
    mxx=mix=v.front().fx(),mxy=miy=v.front().fy();
    for(node it:v){
        int val=max(mxx-it.fx(),max(it.fx()-mix,max(mxy-it.fy(),it.fy()-miy)));
        if(val<=k)dp[it.x][it.y]=1,mxx=max(mxx,it.fx()),mix=min(mix,it.fx()),mxy=max(mxy,it.fy()),miy=min(miy,it.fy());
    }
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++)putchar(dp[i][o]?'M':'G');puts("");
    }
    return  0;
}