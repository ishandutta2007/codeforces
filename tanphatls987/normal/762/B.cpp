#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> lli;

#define X first
#define Y second
const int N=3e5+10;
const ll inf=1e16;
vector <int> a[2];
ll p[2][N];

int o1,o2,bo;
bool comp(lli a,lli b){
    if (a.Y!=b.Y) return a.Y>b.Y;
    return a.X<b.X;
}
int main(){
    int n,val;
    string s;
    cin>>o1>>o2>>bo>>n;
//    string s;
    while (n--){
        cin>>val>>s;
        a[s[0]=='P'].push_back(val);
    }
    for(int i=0;i<=1;i++) {
        sort(a[i].begin(),a[i].end());
        for(int j=0;j<a[i].size();j++) p[i][j+1]=p[i][j]+a[i][j];
    }
    lli ans(inf,0);
    for(int i=0;i<=min(int(a[1].size()),o2+bo);i++){
        int u1=min(i,o2);
        int ub=i-u1;
        int rem=min(int(a[0].size()),bo-ub+o1);
//        cout<<i<<" "<<u1+ub+rem<<" "<<p[1][u1]+p[0][rem]<<'\n';
        ans=min(ans,lli(p[1][i]+p[0][rem],u1+ub+rem),comp);
    }
    cout<<ans.Y<<" "<<ans.X;
}