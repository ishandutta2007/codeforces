#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=17;
int n,m,u;
vector<int> vec[maxn];
int s,sum[maxn],delt[maxn];
map<int,int> p;
bool vis[maxn];
bool dp[1<<20];
vector<pair<int,int> > sol[1<<20];
pair<int,int> aaaa[20];
int trace_back[1<<20];

void dfs(int c){
    int idx=p[c],u=c,ans=0;
    memset(vis,0,sizeof(vis));
    vector<pair<int,int> > tmp;
    while (1){
        if (idx==0||vis[idx]) return;
        vis[idx]=1;
        u-=sum[idx];
        ans+=(1<<(idx-1));
        tmp.push_back({u,idx});
        idx=p[u];
        if (u==c) break;
    }
    sol[ans]=tmp;
    dp[ans]=1;
//    cout<<c<<" "<<ans<<endl;
}

vector<int> adfs(int u){
    vector<int> v;
    v.clear();
    v.push_back(0);
    for (int i=0;i<n;++i){
        if (u>>i&1){
            int t=v.size();
            for (int j=0;j<t;++j){
                v.push_back(v[j]+(1<<i));
            }
        }
    }
    return v;
}

void get_ans(int u){
//    cout<<u<<" "<<trace_back[u]<<endl;
    if (trace_back[u]){
        get_ans(trace_back[u]);
        get_ans(u^trace_back[u]);
    }
    else{
        for (auto c:sol[u]){
            aaaa[p[c.first]]=c;
            //cout<<c.first<<" "<<c.second<<endl;
        }
    }
}
#undef int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>m;
        sum[i]=0;
        for (int j=1;j<=m;++j){
            cin>>u;
            vec[i].push_back(u);
            sum[i]+=u;
            p.insert({u,i});
        }
        s+=sum[i];
    }
    if (s%n){
        printf("NO");
        return 0;
    }
    s/=n;
    for (int i=1;i<=n;++i){
        sum[i]-=s;
    }
    dp[0]=1;
    for (int i=1;i<=n;++i){
        for (auto c:vec[i]){
            dfs(c);
        }
    }
    for (int i=1;i<(1<<n);++i){
        if (dp[i]) continue;
        for (int c=i;c;c=(c-1)&i){
            if (dp[c]&&dp[i^c]){
                dp[i]=1;
                trace_back[i]=c;
    //            cout<<i<<" "<<c<<endl;
                break;
            }
        }
    }
    if (dp[(1<<n)-1]){
        cout<<"Yes"<<endl;
        get_ans((1<<n)-1);
        for (int i=1;i<=n;++i){
            cout<<aaaa[i].first<<" "<<aaaa[i].second<<endl;
        }
    }
    else{
        cout<<"No"<<endl;
        return 0;
    }
    return 0;
}