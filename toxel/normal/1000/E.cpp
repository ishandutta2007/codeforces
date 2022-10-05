#include<bits/stdc++.h>
#define max_N (1000005)
#define max_M (2000005)
struct edge{
    int v,n;
}e[max_M<<1];
int head[max_N],tot=1;
//i2i2i+1
inline void add_edge(int u,int v){
    e[++tot]={v,head[u]},head[u]=tot;
    e[++tot]={u,head[v]},head[v]=tot;
}
class Tarjan{
    private:
        int st[max_M<<1],top;
        std::stack<int>stack;
    public:
        int dfn[max_N],low[max_N],cnt;
        bool cut[max_N],bridge[max_M];
        //bccnobcc1
        int bccno[max_N],bcc_cnt;
        std::vector<int>bcc[max_N];
        //ebcc1
        int ebccno[max_N],ebcc_cnt;
        std::vector<int>ebcc[max_N];
        inline void init(int n,int m){
            cnt=bcc_cnt=ebcc_cnt=0;
            for(int i=1;i<=n;++i)dfn[i]=cut[i]=bccno[i]=ebccno[i]=0;
            for(int i=1;i<=m;++i)bridge[i]=0;
        }
        void dfs(int x,int p){//p0
            low[x]=dfn[x]=++cnt;
            stack.push(x);
            int ch=0;
            for(int i=head[x],y;i;i=e[i].n){
                y=e[i].v;
                if(y==p)continue;
                if(!dfn[y]){
                    st[++top]=i;
                    ++ch,dfs(y,x);
                    low[x]=std::min(low[x],low[y]);
                    if(dfn[x]<=low[y]){
                        cut[x]=1;
                        bcc[++bcc_cnt].clear();
                        for(int j,u,v;;){
                            j=st[top--];
                            u=e[j^1].v,v=e[j].v;
                            if(bccno[u]!=bcc_cnt)bcc[bccno[u]=bcc_cnt].push_back(u);
                            if(bccno[v]!=bcc_cnt)bcc[bccno[v]=bcc_cnt].push_back(v);
                            if(j==i)break;
                        }
                    }
                    if(dfn[x]<low[y])bridge[i>>1]=1;
                    //
                }
                else if(dfn[y]<dfn[x]){
                    st[++top]=i;
                    low[x]=std::min(low[x],dfn[y]);
                }
            }
            if(!p&&ch==1)cut[x]=0;
            //dfs
            if(dfn[x]==low[x]){
                ebcc[++ebcc_cnt].clear();
                ebccno[x]=ebcc_cnt;
                ebcc[ebcc_cnt].push_back(x);
                while(stack.top()!=x){
                    ebccno[stack.top()]=ebcc_cnt;
                    ebcc[ebcc_cnt].push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
        }
};

const int N = 300010;

std::vector <int> vec[N];
Tarjan t;
int u[N], v[N];
int dis[N];

void dfs(int u, int fa){
    for (auto v : vec[u]){
        if (v == fa) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &u[i], &v[i]);
        add_edge(u[i], v[i]);
    }
    t.init(n, m);
    t.dfs(1, 0);
    for (int i = 0; i < m; ++ i){
        int x = t.ebccno[u[i]], y = t.ebccno[v[i]];
        if (x != y){
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
    }
    dfs(1, 0);
    int sit = 1;
    for (int i = 1; i <= t.ebcc_cnt; ++ i){
        if (dis[i] > dis[sit]){
            sit = i;
        }
    }
    dis[sit] = 0;
    dfs(sit, 0);
    int ans = 0;
    for (int i = 1; i <= t.ebcc_cnt; ++ i){
        ans = std::max(ans, dis[i]);
    }
    printf("%d\n", ans);
    return 0;
}