#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int N=2e5+10;
const int MOD=1e9+9;
const int BASE=1000*1000*1000;

int n;
ll a[N][2],w[N];
vector <ll> coor[2];

ll rW[N];
pll B[N];
pll operator *(const pll &a,const pll &b){
        return pll(a.X*b.X*BASE+a.Y*b.X+a.X*b.Y+a.Y*b.Y/BASE,a.Y*b.Y%BASE);
}
bool operator ==(const pll &a,const pll &b){
        return ((a.X==b.X)&&(a.Y==b.Y));
}
void prepare(){
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i][0]>>a[i][1]>>w[i];
        for(int j=0;j<=1;j++){
                for(int i=1;i<=n;i++) coor[j].push_back(a[i][j]);
                sort(coor[j].begin(),coor[j].end());
                coor[j].resize(unique(coor[j].begin(),coor[j].end())-coor[j].begin());
        }
        if (1LL*coor[0].size()*coor[1].size()!=n){
                cout<<"0";
                exit(0);
        }
        /*
        if (coor[0].size()>coor[1].size()){
                coor[0].swap(coor[1]);
                for(int i=1;i<=n;i++) swap(a[i][0],a[i][1]);
        }*/
        for(int j=0;j<=1;j++){
                for(int i=1;i<=n;i++) 
                        a[i][j]=lower_bound(coor[j].begin(),coor[j].end(),a[i][j])-coor[j].begin();
        }
        for(int i=1;i<=n;i++){
                int idx=a[i][0]*coor[1].size()+a[i][1];
                B[idx]=pll(w[i]/BASE,w[i]%BASE);
                rW[idx]=w[i];
        }
}
int solve(){
        int n1=coor[1].size();
        for(int i=0;i<n;i++){
                int ri=i/n1,rj=i%n1;
                if (!((B[i]*B[0])==(B[ri*n1]*B[rj]))) return 0;
        }
        ll Lbound=0,Rbound=0;
        for(int i=0;i<n1;i++) Rbound=__gcd(Rbound,rW[i]);
        for(int i=0;i<coor[0].size();i++) Lbound=__gcd(Lbound,__gcd(rW[i*n1],rW[0]));
        Lbound=rW[0]/Lbound;
        int ans=0;
        for(ll i=1;i*i<=rW[0];i++) if (rW[0]%i==0){
                if (Rbound%i==0&&i%Lbound==0) ans++;
                ll ni=rW[0]/i;
                if (i==ni) continue;
                if (Rbound%ni==0&&ni%Lbound==0) ans++;
        }
        return ans;
}
int main(){
        prepare();
        cout<<solve();
}