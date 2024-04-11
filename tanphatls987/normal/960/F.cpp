#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;

const int N=1e5+10;
const int MOD=1e9+7;

int n,m;
int w[N][3];

vector <ii> v[N];
struct BIT{
        vector <int> b;
        void build(int n){
                b.resize(n+1,0);
        }
        void add(int x,int val){
                while (x){
                        b[x]=max(b[x],val);
                        x-=x&-x;
                }
        }
        int get(int x){
                int ans=0;
                while (x<b.size()){
                        ans=max(ans,b[x]);
                        x+=x&-x;
                }
                return ans;
        }
}mbit[N];
void prepare(){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
                for(int j=0;j<3;j++) cin>>w[i][j];
                v[w[i][0]].push_back(ii(w[i][2],w[i][1]));
        }
        for(int i=1;i<=n;i++){
                sort(v[i].begin(),v[i].end());
                mbit[i].build(v[i].size());
        }
}
int solve(){
        int ans=0;
        for(int i=m;i>=1;i--){
                int pos=lower_bound(v[w[i][1]].begin(),v[w[i][1]].end(),ii(w[i][2]+1,0))-v[w[i][1]].begin()+1;
                int rpos=lower_bound(v[w[i][0]].begin(),v[w[i][0]].end(),ii(w[i][2],w[i][1]))-v[w[i][0]].begin()+1;
                int cans=mbit[w[i][1]].get(pos)+1;
                mbit[w[i][0]].add(rpos,cans);
                ans=max(ans,cans);
        }
        return ans;
}
int main(){
        prepare();
        cout<<solve();
}