#include <bits/stdc++.h>

using namespace std;


int n,d[305];

int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>d[i];

        vector <pair<int,int> > ans;
        for(int L=1,R=d[n]+1,pL=1,pR=n;L<=R;){
                for(int i=L;i<R;i++) ans.push_back(make_pair(i,R));
                R--;
                for(int i=pL;i<=pR;i++) d[i]--;
                if (d[pL]==0){
                        pL++;
                        L++;
                        if (R-L<d[pR]) pR--;
                        if (pR<pL) break;
                        R=L+d[pR];
                }
        }
        cout<<ans.size()<<'\n';
        for(auto i:ans) cout<<i.first<<" "<<i.second<<'\n';
}