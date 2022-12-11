#include <bits/stdc++.h>

using namespace std;

queue <int> q;
map <int,int> ma;
int main(){
    int x,y;
    cin>>x>>y;
    ma[x]=-1;
    q.push(x);
    while (!q.empty()){
        int cur=q.front();q.pop();
        if (2LL*cur<=y&&ma[2LL*cur]==0){
            q.push(2*cur);
            ma[2*cur]=cur;
        }
        if (10LL*cur+1<=y&&ma[10LL*cur+1]==0){
            q.push(10LL*cur+1);
            ma[10*cur+1]=cur;
        }
    }
    if (!ma[y]){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    vector <int> ans;
    while (y!=-1) ans.push_back(y),y=ma[y];
    printf("%d\n",ans.size());
    reverse(ans.begin(),ans.end());
    for(auto i:ans) printf("%d ",i);
}