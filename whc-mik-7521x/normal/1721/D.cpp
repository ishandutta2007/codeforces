#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        vector<pair<vector<int>,vector<int>>>now,kk;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        now.clear();
        now.push_back({{},{}});
        for(int i=1;i<=n;i++)now.back().first.push_back(a[i]),now.back().second.push_back(b[i]);
        int ans=0;
        for(int i=29;i>=0;i--){
            int pd=1;
            kk.clear();
            for(auto it:now){
                pair<vector<int>,vector<int>>p1,p2;
                p1={{},{}};
                p2={{},{}};
                int ct1=0,ct0=0;
                for(int o:it.first)((1<<i)&o)?(ct1++,p1.first.push_back(o)):(ct0++,p2.first.push_back(o));
                for(int o:it.second)((1<<i)&o)?(ct0--,p2.second.push_back(o)):(ct1--,p1.second.push_back(o));
                if(ct1||ct0)pd=0;
                if(p1.first.size())kk.push_back(p1);
                if(p2.first.size())kk.push_back(p2);
            }
            if(pd)now=kk,ans|=1<<i;
        }
        printf("%d\n",ans);
    }
    return 0;
}