#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> range;

#define X first
#define Y second

const int N=1e5+10,M=350;
const int MOD=1e9+7;

int n,a[N];
vector <int> v[N];
int f[N][M],id[N];
int s[N];
void prepare(){
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=n;i++) v[i].push_back(i);
    while (m--){
        int L,R;
        cin>>L>>R;
        a[R]=L;
        v[L].push_back(R);
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());

    for(int cur=1;cur*M<=n;cur++){
        for(int i=1;i<=cur*M;i++)
            while (id[i]+1<v[i].size()&&v[i][id[i]+1]<=cur*M) id[i]++;
        int top=0;
        s[0]=cur*M+1;
        f[s[0]][cur]=s[0];
        for(int i=cur*M;i>=1;i--){
            f[i][cur]=v[i][id[i]];
            while (top&&s[top-1]<=v[i][id[i]]) top--;
            if (v[i][id[i]]>=s[top]) f[i][cur]=max(f[i][cur],f[s[top]][cur]);
            while (f[i][cur]>=f[s[top]][cur]) top--;
            s[++top]=i;
        }
    }
}
int solve(int L,int R){
    int len=R-L+1;
    if (len<=M){
        int ans=L;
        for(int i=L;i<=R;i++) if (a[i]>=L&&a[i]<=ans) ans=i;
        return ans;
    }
    int ans=f[L][R/M];
    for(int i=R/M*M;i<=R;i++) if (a[i]>=L&&a[i]<=ans) ans=i;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prepare();
    int test;
    cin>>test;
    while (test--){
        int L,R;
        cin>>L>>R;
        cout<<solve(L,R)<<'\n';
    }
}