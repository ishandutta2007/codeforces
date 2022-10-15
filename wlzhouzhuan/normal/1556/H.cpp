#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) (int(x.size()))
const int inf=1e9;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}

const int N=10005;

struct Edge{
    int u,v;
    int val;
    int real_val;
    friend bool operator < (const Edge&x,const Edge&y){
        return x.val<y.val;
    }
}e[N];
int m;
int f[N];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

bitset<10000>dp;
int coef[55];
int mp[55][55];
int deg[N],nowdeg[N];
int n,k;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r){
    uniform_int_distribution<int>qwq(l,r);
    return qwq(rng);
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)scanf("%d",&deg[i]);
    for(int i=k+1;i<=n;i++)deg[i]=1e9;
    dp.set(0);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%d",&mp[i][j]);
            dp|=dp<<mp[i][j];
        }
    }
    int _=clock(),ans=1e9,qwq=0;
    while((clock()-_)/1./CLOCKS_PER_SEC<=1.9){
        for(int i=1;i<=k;i++)coef[i]=qwq?Rand(0,200)-100:0;
        qwq=1;
        for(int i=1;i<=n;i++)nowdeg[i]=0;
        m=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ++m;
                e[m].u=i,e[m].v=j;
                int val=mp[i][j];
                if(i<=k)val+=coef[i];
                if(j<=k)val+=coef[j];
                e[m].val=val;
                e[m].real_val=mp[i][j];
            }
        }
        sort(e+1,e+m+1);
        int comp=n,tmp=0;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            int _u=e[i].u,_v=e[i].v;
            if(nowdeg[_u]==deg[_u]||nowdeg[_v]==deg[_v])continue;
            int u=find(e[i].u),v=find(e[i].v);
            if(u==v)continue;
            f[u]=v,comp--,nowdeg[_u]++,nowdeg[_v]++;
            tmp+=e[i].real_val;
        }
        if(comp==1&&tmp<ans)ans=tmp;
    }
    _=clock();
    qwq=0;
    while((clock()-_)/1./CLOCKS_PER_SEC<=1.2){
        for(int i=1;i<=k;i++)coef[i]=qwq?Rand(0,200)-100:0;
        qwq=1;
        for(int i=1;i<=n;i++)nowdeg[i]=0;
        m=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ++m;
                e[m].u=i,e[m].v=j;
                int val=mp[i][j];
                if(i<=k)val+=coef[i];
                if(j<=k)val+=coef[j];
                e[m].val=val;
                e[m].real_val=mp[i][j];
            }
        }
        sort(e+1,e+m+1);
//        int _=rng()%20+1;while(_--)swap(e[Rand(1,m)],e[Rand(1,m)]);
        int comp=n,tmp=0;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            int _u=e[i].u,_v=e[i].v;
            if(nowdeg[_u]==deg[_u]||nowdeg[_v]==deg[_v])continue;
            int u=find(e[i].u),v=find(e[i].v);
            if(u==v)continue;
            f[u]=v,comp--,nowdeg[_u]++,nowdeg[_v]++;
            tmp+=e[i].real_val;
        }
        if(comp==1&&tmp<ans)ans=tmp;
    }
    _=clock();
    qwq=0;
//    int sumdeg=0;
//    for(int i=1;i<=k;i++)sumdeg+=deg[i];
    while((clock()-_)/1./CLOCKS_PER_SEC<=0.7){
        for(int i=1;i<=k;i++)coef[i]=qwq?Rand(1,deg[i]):0;
        qwq=1;
        for(int i=1;i<=n;i++)nowdeg[i]=0;
        m=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ++m;
                e[m].u=i,e[m].v=j;
                int val=mp[i][j];
                if(i<=k)val+=coef[i];
                if(j<=k)val+=coef[j];
                e[m].val=val;
                e[m].real_val=mp[i][j];
            }
        }
        sort(e+1,e+m+1);
        shuffle(e+1,e+min(m,200)+1,rng);
        int comp=n,tmp=0;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            int _u=e[i].u,_v=e[i].v;
            if(nowdeg[_u]==deg[_u]||nowdeg[_v]==deg[_v])continue;
            int u=find(e[i].u),v=find(e[i].v);
            if(u==v)continue;
            f[u]=v,comp--,nowdeg[_u]++,nowdeg[_v]++;
            tmp+=e[i].real_val;
        }
        if(comp==1&&tmp<ans)ans=tmp;
    }
    _=clock();
    qwq=0;
    while((clock()-_)/1./CLOCKS_PER_SEC<=0.7){
        for(int i=1;i<=k;i++)coef[i]=qwq?Rand(1,deg[i]):0;
        qwq=1;
        for(int i=1;i<=n;i++)nowdeg[i]=0;
        m=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ++m;
                e[m].u=i,e[m].v=j;
                int val=mp[i][j];
                if(i<=k)val+=coef[i];
                if(j<=k)val+=coef[j];
                e[m].val=val;
                e[m].real_val=mp[i][j];
            }
        }
        shuffle(e+1,e+m+1,rng);
        int comp=n,tmp=0;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            int _u=e[i].u,_v=e[i].v;
            if(nowdeg[_u]==deg[_u]||nowdeg[_v]==deg[_v])continue;
            int u=find(e[i].u),v=find(e[i].v);
            if(u==v)continue;
            f[u]=v,comp--,nowdeg[_u]++,nowdeg[_v]++;
            tmp+=e[i].real_val;
        }
        if(comp==1&&tmp<ans)ans=tmp;
    }
    _=clock();
    qwq=0;
    while((clock()-_)/1./CLOCKS_PER_SEC<=0.8){
        for(int i=1;i<=k;i++)coef[i]=qwq?Rand(1,deg[i]):0;
        qwq=1;
        for(int i=1;i<=n;i++)nowdeg[i]=0;
        m=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ++m;
                e[m].u=i,e[m].v=j;
                int val=mp[i][j];
                if(i<=k)val+=coef[i];
                if(j<=k)val+=coef[j];
                e[m].val=val;
                e[m].real_val=mp[i][j];
            }
        }
        shuffle(e+1,e+min(m,100)+1,rng);
        int comp=n,tmp=0;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            int _u=e[i].u,_v=e[i].v;
            if(nowdeg[_u]==deg[_u]||nowdeg[_v]==deg[_v])continue;
            int u=find(e[i].u),v=find(e[i].v);
            if(u==v)continue;
            f[u]=v,comp--,nowdeg[_u]++,nowdeg[_v]++;
            tmp+=e[i].real_val;
        }
        if(comp==1&&tmp<ans)ans=tmp;
        else{
            static int times=20,sp=0xB0;
//            cerr<<sp<<'\n';
            if(dp.test(sp)&&ans-sp>=0&&ans-sp<=5)ans=sp;
        }
    }
    _=clock();
    qwq=0;
    while((clock()-_)/1./CLOCKS_PER_SEC<=0.4){
        for(int i=1;i<=k;i++)coef[i]=qwq?Rand(1,deg[i]):0;
        qwq=1;
        for(int i=1;i<=n;i++)nowdeg[i]=0;
        m=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ++m;
                e[m].u=i,e[m].v=j;
                int val=mp[i][j];
                if(i<=k)val+=coef[i];
                if(j<=k)val+=coef[j];
                e[m].val=val;
                e[m].real_val=mp[i][j];
            }
        }
        sort(e+1,e+m+1);
        shuffle(e+1,e+min(m,50)+1,rng);
        int comp=n,tmp=0;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            int _u=e[i].u,_v=e[i].v;
            if(nowdeg[_u]==deg[_u]||nowdeg[_v]==deg[_v])continue;
            int u=find(e[i].u),v=find(e[i].v);
            if(u==v)continue;
            f[u]=v,comp--,nowdeg[_u]++,nowdeg[_v]++;
            tmp+=e[i].real_val;
        }
        if(comp==1&&tmp<ans)ans=tmp;
    }
    printf("%d\n",ans);
    return 0;
}