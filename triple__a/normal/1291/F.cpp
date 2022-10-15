#include<bits/stdc++.h>
using namespace std;

const int maxn=1027;
int n,k,b;
bool vis[maxn];
bool query(int u){
    cout<<"? "<<u<<endl;
    char c;
    cin>>c;
    return c=='Y';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    b=(k+1)/2;
    for (int i=0;i<n/b;++i){
        for (int j=i+1;j<n/b;++j){
            for (int k=1;k<=b;++k){
                if (query(i*b+k))vis[i*b+k]=1;
            }
            for (int k=1;k<=b;++k){
                if (query(j*b+k)) vis[j*b+k]=1;
            }
            cout<<"R"<<endl;
        }
    }
    int ans=0;
    for (int i=1;i<=n;++i) ans+=1-vis[i];
    cout<<"! "<<ans<<endl;
    return 0;
}