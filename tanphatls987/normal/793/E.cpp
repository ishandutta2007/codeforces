#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> range;

#define X first
#define Y second

const int N=5e3+10;

int n,p[2][2],gr[2][2];
int pa[N],sub[N];

vector <int> v[N];
int fs[2][N];

int f[N];
void prepare(){
    cin>>n;
    for(int i=0;i<=1;i++) cin>>p[i][0]>>p[i][1];
    for(int i=2;i<=n;i++) cin>>pa[i];
    for(int i=n;i>=1;i--){
        v[pa[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) sub[i]=v[i].empty();
    for(int i=n;i>=1;i--) sub[pa[i]]+=sub[i];
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++) {
            gr[i][j]=p[i][j];
            while (pa[gr[i][j]]!=1) gr[i][j]=pa[gr[i][j]];
        }
}
string solve(){
    if (sub[1]&1) return "NO";
    for(int pha=0;pha<=1;pha++){
        for(int j=0;j<=1;j++){
            int cur=p[pha][j];
            memset(fs[j],0,sizeof(fs[j]));
            fs[j][1]=1;
            int nknap=1;
            while (cur!=1){
                int z=pa[cur];
                for(auto x:v[z]) if (x!=cur){
                    for(int i=nknap;i>=1;i--) if (fs[j][i]) fs[j][i+sub[x]]=1;
                    nknap+=sub[x];
                }
                cur=pa[cur];
            }
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=sub[gr[pha][0]];i++) if (fs[0][i])
            for(int j=1;j<=sub[gr[pha][1]];j++) if (fs[1][j])
                f[i+j]=1;
        int nknap=sub[gr[pha][0]]+sub[gr[pha][1]];
        for(auto x:v[1]){
            if (x==gr[pha][0]||x==gr[pha][1]||x==gr[pha^1][pha]) continue;
            for(int i=nknap;i>=1;i--) if (f[i]) f[i+sub[x]]=1;
            nknap+=sub[x];
        }
        if (!f[sub[1]/2]) return "NO";
    }
    return "YES";
}
int main(){
    prepare();
    cout<<solve();
}