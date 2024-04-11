#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        vector<int>a[N];
        for(int i=1;i<=n;i++){
            a[i].resize(m+1);
            for(int o=1;o<=m;o++){
                scanf("%d",&a[i][o]);
            }
        }
        set<pair<int,int>>st;
        int sp1=1,sp2=1;
        for(int i=1;i<=n;i++){
            vector<int>vec=a[i],now;
            stable_sort(vec.begin()+1,vec.end());
            for(int o=1;o<=m;o++){
                if(a[i][o]!=vec[o])now.push_back(o);
            }
            if(now.size()==2)sp1=now[0],sp2=now[1];
        }
        int pd=0;
        for(int i=1;i<=n;i++){
            vector<int>vec=a[i];
            stable_sort(vec.begin()+1,vec.end());
            swap(a[i][sp1],a[i][sp2]);
            if(a[i]!=vec)pd=1;
        }
        if(pd)puts("-1");
        else printf("%d %d\n",sp1,sp2);
    }
    return  0;
}