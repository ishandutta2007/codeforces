#include <bits/stdc++.h>

using namespace std;

const int inf=1e9+10;
const int N=1e3+10;

int n;
vector <int> ques[10][2];
int ans[N],w[N]
;

void decomp(int L,int R,int lv){
    if (L==R) return;
    int mid=(L+R)/2;
    for(int i=L;i<=mid;i++) ques[lv][0].push_back(i);
    for(int i=mid+1;i<=R;i++) ques[lv][1].push_back(i);
    decomp(L,mid,lv+1);
    decomp(mid+1,R,lv+1);
}
int main(){
    cin>>n;
    decomp(1,n,0);
    fill(ans+1,ans+n+1,inf);
    for(int lv=0;lv<10;lv++)
        for(int i=0;i<=1;i++) if (!ques[lv][i].empty()){
            cout<<ques[lv][i].size()<<'\n';
            for(auto j:ques[lv][i]) cout<<j<<" ";
            cout<<'\n';
            fflush(stdout);
            for(int j=1;j<=n;j++) cin>>w[j];
            for(auto j:ques[lv][i^1]) ans[j]=min(ans[j],w[j]);
        }
    cout<<"-1\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    fflush(stdout);
}