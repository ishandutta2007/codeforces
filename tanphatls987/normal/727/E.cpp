#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second

const int N=2e6+10;

const int MOD=1e9+7;
const ll BASE[2]={43,37};

ll ha[2][N],pb[2][N];
int n,k,n1,h[N];
string s,dict[100005];
map <ii,int> ma;

ii gethash(int L,int R){
    ii ans;
    ans.X=(ha[0][R]-ha[0][L-1]*pb[0][R-L+1]%MOD+MOD)%MOD;
    ans.Y=(ha[1][R]-ha[1][L-1]*pb[1][R-L+1]%MOD+MOD)%MOD;
    return ans;
}
void prepare(){
    for(int j=0;j<=1;j++){
        pb[j][0]=1;
        for(int i=1;i<N;i++) pb[j][i]=pb[j][i-1]*BASE[j]%MOD;
    }
    cin>>n>>k>>s;
    s=s+s;
    cin>>n1;
    for(int i=1;i<=n1;i++){
        cin>>dict[i];
        ii chash=ii(0,0);
        for(auto ch:dict[i]) {
            chash.X=(chash.X*BASE[0]+ch-'a')%MOD;
            chash.Y=(chash.Y*BASE[1]+ch-'a')%MOD;
        }
        ma[chash]=i;
    }
    for(int i=1;i<=2*n*k;i++)
        for(int j=0;j<=1;j++) ha[j][i]=(ha[j][i-1]*BASE[j]+s[i-1]-'a')%MOD;
//    for(int i=1;i<=2*n*k;i++) cout<<ha[i]<<" ";printf("\n");
}
vector <int> ans;

bool check(int st){
    vector <int> use;
    bool okay=1;
    for(int i=0;i<n;i++,st+=k){
        auto ite=ma.find(gethash(st,st+k-1));
        if (ite==ma.end()||h[ite->second]) {
            okay=0;
            break;
        }
        h[ite->second]=1;
        use.push_back(ite->second);
    }
//    cout<<st<<" "<<okay<<'\n';
    for(auto i:use) h[i]=0;
    return okay;
}
bool recheck(int st){
    int cst=st;
    for(int i=0;i<n;i++,st+=k){
        int idx=ma[gethash(st,st+k-1)];
        if (s.substr(st-1,k)!=dict[idx]) return 0;
    }
    st=cst;
    for(int i=0;i<n;i++,st+=k){
        int idx=ma[gethash(st,st+k-1)];
        ans.push_back(idx);
    }
    return 1;
}
void solve(){
    for(int st=1;st<=k;st++){
        if (check(st)&&recheck(st)){
            printf("YES\n");
            for(auto i:ans) printf("%d ",i);
            return;
        }
    }
    printf("NO");
}
int main(){
    prepare();
    solve();
}