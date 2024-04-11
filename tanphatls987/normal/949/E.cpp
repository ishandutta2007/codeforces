#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int bar=(1<<18)+5;
vector <int> ans,cans;


int a[19][(1<<19)+20];
void DP(int ra){
        int low=-(1<<ra)+1,hi=(1<<ra)-1;
        if (ra==1){
                for(int i=-1;i<=1;i+=2) if (a[ra][i+bar]) 
                        cans.push_back(i*(1<<17));
                if (cans.size()<ans.size()) ans=cans;
                for(int i=-1;i<=1;i+=2) if (a[ra][i+bar])
                        cans.pop_back();
                return;
        }
        int odd=0;
        for(int i=low;i<=hi;i++) if (i%2&&a[ra][i+bar]) odd=1;
        for(int use=-odd;use<2;use+=2){
                for(int i=low;i<=hi;i++) if (a[ra][i+bar]){
                        int ni=(i%2)?((i-use)/2):(i/2);
                        a[ra-1][ni+bar]=1;
                }
                if (use!=0) cans.push_back(use*(1<<(18-ra)));
                DP(ra-1);
                if (use!=0) cans.pop_back();
                for(int i=low;i<=hi;i++) if (a[ra][i+bar]){
                        int ni=(i%2)?((i-use)/2):(i/2);
                        a[ra-1][ni+bar]=0;
                }
        }
}
int main(){
        int n;
        cin>>n;
        while (n--){
                int val;
                cin>>val;
                a[18][val+bar]=1;
        }
        ans.resize(21);
        DP(18);
        cout<<ans.size()<<'\n';
        for(auto i:ans) cout<<i<<" ";
}