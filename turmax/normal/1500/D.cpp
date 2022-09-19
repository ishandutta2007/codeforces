#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1505;
bool ok[maxn][maxn];
vector<int> a[maxn][maxn];
int c[maxn][maxn];
int ans[maxn][maxn];
int t[maxn];int res[maxn];
vector<int> v1,v2,v3,v4,v5;
bool ok4[maxn*maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    v1.reserve(50);v2.reserve(50);v3.reserve(50);v4.reserve(50);
    int n,q;scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) {scanf("%d",&c[i][j]);a[i][j]={c[i][j]};ok[i][j]=true;}
    int cur=1;
    while(cur<2*n)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(!ok[i][j]) continue;
                bool ok1=(i+2*cur<=n && j+2*cur<=n && ok[i+cur][j] && ok[i][j+cur] && ok[i+cur][j+cur]);
                if(ok1)
                {
                v1=a[i][j];v2=a[i+cur][j];v3=a[i][j+cur];v4=a[i+cur][j+cur];v5.clear();
                for(int i:v1) {ok4[i]=true;}
                for(int i:v2) {if(!ok4[i]) {ok4[i]=true;v1.push_back(i);}}
                if(v1.size()>q) {ok1=false;}
                else {
                for(int i:v3) {if(!ok4[i]) {ok4[i]=true;v1.push_back(i);}}
                if(v1.size()>q) {ok1=false;}
                else {
                for(int i:v4) {if(!ok4[i]) {ok4[i]=true;v1.push_back(i);}}}}
                }
                for(int i:v1) ok4[i]=false;
                ok1=(ok1 && v1.size()<=q);
                if(!ok1)
                {
                    ok[i][j]=false;
                    int low=0;
                    if(i>=1 && !ok[i-1][j])
                    {
                        low=max(low,ans[i-1][j]-cur-1);
                    }
                    int up=cur;
                    while(low<up-1)
                    {
                        int mid=low+1;
                        if(i+cur+mid>n || j+cur+mid>n || !ok[i+mid][j] || !ok[i][j+mid] || !ok[i+mid][j+mid]) {break;}
                        v1=a[i][j];v2=a[i+mid][j];v3=a[i][j+mid];v4=a[i+mid][j+mid];
                        bool ok2=true;
                        for(int i:v1) {ok4[i]=true;}
                for(int i:v2) {if(!ok4[i]) {ok4[i]=true;v1.push_back(i);}}
                if(v1.size()>q) {ok2=false;}
                else {
                for(int i:v3) {if(!ok4[i]) {ok4[i]=true;v1.push_back(i);}}
                if(v1.size()>q) {ok2=false;}
                else {
                for(int i:v4) {if(!ok4[i]) {ok4[i]=true;v1.push_back(i);}}}}
                        for(int i:v1) ok4[i]=false;
                        if(ok2 && v1.size()<=q) {++low;continue;}
                        else {break;}
                    }
                    ans[i][j]=cur+low;
                }
                else
                {
                    a[i][j]=v1;
                }
            }
        }
        cur*=2;
    }
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) t[ans[i][j]]++;
    int sum=0;
    for(int i=n;i>=1;--i) {sum+=t[i];res[i]=sum;}
    for(int i=1;i<=n;++i) cout<<res[i]<<'\n';
    return 0;
}