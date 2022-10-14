
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

bool Valid(int x,int y,int n,int m){
    return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
    for(int t=ri();t>0;t--){
        int n,m;
        scanf("%i %i",&n,&m);
        int a[n][m],ans=0,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%i",&a[i][j]),ans+=a[i][j];
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int nx=i+dx[k],j+dy[k];
                    if(Valid(nx,ny,n,m)&&a[i][j]<0&&a[nx][ny]<0)a[i][j]*=-1,a[nx][ny]*=-1;
                }
            }
        }*/
        bool ok=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0)ok=1;
                /*for(int k=0;k<4;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(Valid(nx,ny,n,m)&&a[i][j]==0&&a[nx][ny]<0)a[i][j]*=-1,a[nx][ny]*=-1;
                }*/
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)sum+=abs(a[i][j]);
        if(ok){
            printf("%i\n",sum);
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(Valid(nx,ny,n,m)&&a[nx][ny]<0)a[i][j]*=-1,a[nx][ny]*=-1;
                }
            }
        }
        vector<int> pos,neg;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]>=0)pos.pb(a[i][j]);
                else neg.pb(a[i][j]);
            }
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        int res=0,j=0;
        for(int i=0;i<(int)pos.size();i++){
            if(j<(int)neg.size()&&abs(neg[j])>=pos[i]){
                res+=abs(neg[j]);
                res-=pos[i];
                j++;
            }else{
                res+=pos[i];
            }
        }
        for(int i=j;i<(int)neg.size();i++)res+=neg[i];
        printf("%i\n",res);
    }
	return 0;
}