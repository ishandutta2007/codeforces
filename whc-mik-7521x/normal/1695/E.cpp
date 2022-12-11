#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct edge{
    int to,nxt,used;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int n,vis[N];
void dfs(int x,vector<int>&vec){
    vec.push_back(x);
    if(vis[x])return;
    vis[x]=1;
    for(int i=h[x];i;i=ed[i].nxt){
        if(ed[i].used)continue;
        int v=ed[i].to;
        ed[i].used=ed[i^1].used=1;
        dfs(v,vec);
        vec.push_back(x);
    }
}
int main(){
    scanf("%d",&n);
    cnt=1;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }  
    vector<vector<int>>ans;
    for(int i=1;i<=n<<1;i++){
        vector<int>vec;
        if(!vis[i]){
            dfs(i,vec);
            if(vec.size()>3)ans.push_back(vec);
            if(vec.size()==3)return puts("-1"),0;
        }
    }
    vector<int>res1,res2;
    for(auto &it:ans){
        it.pop_back();
        for(int i=0;i<(int)it.size()>>1;i++)res1.push_back(it[i]);
        for(int i=it.size()-1;i>=(int)it.size()>>1;i--)res2.push_back(it[i]);
    }
    printf("2 %d\n\n",(int)res1.size());
    for(auto it:res1)printf("%d ",it);
    puts("");
    for(auto it:res2)printf("%d ",it);
    printf("\n\n");
    string s1,s2,s3,s4;
    for(auto &it:ans){
        int kk=it.size();
        kk>>=1;
        if(kk&1){
            s3+="U";
            s4+="D";
            for(int i=1;i<=kk>>1;i++)s1+="LR",s2+="LR",s3+="LR",s4+="LR";
            s1+="U";
            s2+="D";
        }
        else{
            s3+="U";
            s4+="D";
            for(int i=1;i<=kk>>1;i++)s1+="LR",s2+="LR";
            for(int i=1;i<kk>>1;i++)s3+="LR",s4+="LR";
            s3+="U";
            s4+="D";
        }
    }
    cout<<s1<<endl<<s2<<endl<<endl<<s3<<endl<<s4;
    return  0;
}