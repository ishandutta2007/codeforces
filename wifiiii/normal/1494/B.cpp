#include<bits/stdc++.h>

//typedef long long ll;
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        int okk=0;
        for(int i=0;i<1<<4;++i) {
            int uu=0,rr=0,dd=0,ll=0;
            for(int j=0;j<4;++j) {
                if(i>>j&1) {
                    if(j==0) uu++,rr++;
                    if(j==1) rr++,dd++;
                    if(j==2) dd++,ll++;
                    if(j==3) ll++,uu++;
                }
            }
            int ok=1;
            if(uu>u || u-uu>n-2) ok=0;
            if(rr>r || r-rr>n-2) ok=0;
            if(dd>d || d-dd>n-2) ok=0;
            if(ll>l || l-ll>n-2) ok=0;
            if(ok) okk=1;
        }
        cout<<(okk?"YES":"NO")<<'\n';
    }
}