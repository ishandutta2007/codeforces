#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=6666;
struct edge{
    int to;
    LL val;
    edge(int v,LL c):to(v),val(c){}
};
int n;
int par[maxn];              // par[i]: i
vector<edge>Tree[maxn];
LL len_par[maxn];           // len_par[i]: i
LL so[maxn];                // so[i]: i
LL sp[maxn];                // sp[i]: ii

void dfs_par(int cnt){
    int len=Tree[cnt].size();
    for(int i=0;i<len;++i){
        int son=Tree[cnt][i].to;
        if(par[son]==son&&son!=0){
            par[son]=cnt;
            len_par[son]=Tree[cnt][i].val;
            dfs_par(son);
        }
    }
}
void dfs_sp(int cnt,LL &val,LL sum){
    val+=sum;  so[cnt]=1;
    int len=Tree[cnt].size();
    for(int i=0;i<len;++i){
        int son=Tree[cnt][i].to;
        if(par[son]==cnt){
            dfs_sp(son,val,sum+Tree[cnt][i].val);
            so[cnt]+=so[son];
        }
    }
}
void dfs_de(int cnt,int toal){
    int len=Tree[cnt].size();
    for(int i=0;i<len;++i){
        int son=Tree[cnt][i].to;
        if(par[son]==cnt){
            sp[son]=sp[cnt]+Tree[cnt][i].val*(toal-2*so[son]);
            //=sp[son]=sp[cnt]-Tree[cnt][i].val*so[son] + Tree[cnt][i].val*(toal-so[son]);
            dfs_de(son,toal);
        }
    }
}
void get_sp(int cnt,int &Min){
    if(sp[Min]>sp[cnt]) Min=cnt;
    int len=Tree[cnt].size();
    for(int i=0;i<len;++i){
        int son=Tree[cnt][i].to;
        if(par[son]==cnt) get_sp(son,Min);
    }
}
int main(){
    cin>>n;            
    for(int i=1;i<n;++i){
        par[i]=i;
        int a,b; LL c;  cin>>a>>b>>c;
        --a, --b;
        Tree[a].push_back(edge(b,c));
        Tree[b].push_back(edge(a,c));
    }
    len_par[0]=par[0]=0;
    dfs_par(0);
    LL ans=-1;
    for(int i=1;i<n;++i){
        int r=par[i]; par[i]=i;
        dfs_sp(0,sp[0],0LL), dfs_sp(i,sp[i],0LL);
        dfs_de(0,so[0]), dfs_de(i,so[i]);
        int g1=0, g2=i;
        get_sp(0,g1), get_sp(i,g2);
        LL sp1=sp[g1], sp2=sp[g2];
        
//        cout<<"--------"<<i<<"--------"<<endl;
//        cout<<"g1="<<g1<<' '<<"g2="<<g2<<endl;
//        for(int i=0;i<n;++i) cout<<sp[i]<<' '; cout<<endl;
        
        LL M=len_par[i]*so[0]*so[i]+sp1*so[i]+sp2*so[0];
        // M:  
        // M: 
        LL p=0LL;
        for(int j=0;j<n;++j) p+=sp[j];  // 
        M+=p/2;
        ans=(ans==-1?M:min(ans,M));
        memset(sp,0LL,sizeof(sp));
        par[i]=r;
    }
    cout<<ans<<endl;
    return 0;
}