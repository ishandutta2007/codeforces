#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define X first
#define Y second

const int N=3e5+10;
const int inf=1e9+10;

int n,a[N][3];
map <ii,int> ma;
set <ii> se[N];

void modified(int x,int y,int z,int idx,int type){
    static int n1=0;
    if (x>y) swap(x,y);
    if (!ma[ii(x,y)]) ma[ii(x,y)]=++n1;
    int pos=ma[ii(x,y)];
    if (type==1) se[pos].insert(ii(z,idx));
    else {
        if (se[pos].count(ii(z,idx)))
            se[pos].erase(ii(z,idx));
    }
}
ii get(int x,int y){
    if (x>y) swap(x,y);
    int idx=ma[ii(x,y)];
    if (se[idx].empty()) return ii(-inf,0);
    return *se[idx].rbegin();
}
void prepare(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++) scanf("%d",a[i]+j);
        for(int j=0;j<3;j++) modified(a[i][j],a[i][(j+1)%3],a[i][(j+2)%3],i,1);
    }
}
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
void solve(){
    vector <int> anss;
    int ans=0;
    for(int i=1;i<=n;i++){
        int crad=*min_element(a[i],a[i]+3);
//        cout<<i<<" "<<crad<<'\n';
        if (maximize(ans,crad)){
            anss={i};
//            anss.clear();
//            anss.push_back(i);
        }
        for(int j=0;j<3;j++) modified(a[i][j],a[i][(j+1)%3],a[i][(j+2)%3],i,-1);
        for(int j=0;j<3;j++){
            int x=a[i][j],y=a[i][(j+1)%3];
            ii cur=get(x,y);
            int crad=min(min(x,y),a[i][(j+2)%3]+cur.X);
//            cout<<i<<" "<<j<<" "<<crad<<'\n';
            if (maximize(ans,crad)){
                anss={i,cur.Y};
            }
        }
    }
    cout<<anss.size()<<'\n';
    for(auto i:anss) cout<<i<<" ";
}
int main(){
    prepare();
    solve();
}