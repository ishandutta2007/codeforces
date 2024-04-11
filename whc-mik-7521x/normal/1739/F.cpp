#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,trie[N][12],ct,w[N],kk[N],cnt[N],tmp[N],fail[N];
pair<int,string>dp[1<<12][4005];
void ins(vector<int>s,int x){
    if(!s.size())return;
    for(int i=0;i<=12;i++)cnt[i]=0;
    for(int i:s)if(cnt[i]++)return;
    int now=0;
    for(int i:s){
        if(!trie[now][i])trie[now][i]=++ct;
        now=trie[now][i];
    }
    w[now]+=x;
}
void build(){
    queue<int>q;
    for(int i=0;i<12;i++)if(trie[0][i])q.push(trie[0][i]);
    while(q.size()){
        int u=q.front();
        q.pop();
        w[u]+=w[fail[u]];
        for(int i=0;i<12;i++){
            if(trie[u][i])fail[trie[u][i]]=trie[fail[u]][i],q.push(trie[u][i]);
            else trie[u][i]=trie[fail[u]][i];
        }
    }
}
vector<int>calc(string s){
    int l=5000,r=5001,now=5001;
    for(int i=5000-50;i<=5000+50;i++)tmp[i]=0;
    tmp[l]=s[0]-'a'+1,tmp[r]=s[1]-'a'+1;
    for(int i=2;i<(int)s.size();i++){
        int kp=s[i]-'a'+1;
        if(tmp[now-1]==kp)now=now-1;
        else if(tmp[now+1]==kp)now=now+1;
        else{
            if(now==r)r+=1,now+=1,tmp[now]=kp;
            else if(now==l)l-=1,now-=1,tmp[now]=kp;
            else return{};
        }
    }
    vector<int>res;
    for(int i=l;i<=r;i++)res.push_back(tmp[i]-1);
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        string s;
        cin>>x>>s;
        auto it=calc(s);
        ins(it,x);
        reverse(it.begin(),it.end());
        ins(it,x);
    }
    build();
    for(int i=0;i<1<<12;i++)for(int o=0;o<=ct;o++)dp[i][o]={-1e9,{}};
    dp[0][0]={0,{}};
    for(int i=0;i<1<<12;i++){
        for(int o=0;o<=ct;o++){
            for(int k=0;k<12;k++){
                if(!(i&(1<<k))){
                    dp[i|(1<<k)][trie[o][k]]=max(dp[i|(1<<k)][trie[o][k]],{dp[i][o].first+w[trie[o][k]],dp[i][o].second+char('a'+k)});
                }
            }
        }
    }
    pair<int,string>ans={-1e9,{}};
    for(int o=0;o<=ct;o++)ans=max(ans,dp[(1<<12)-1][o]);
    cout<<ans.second;
    return 0;
}