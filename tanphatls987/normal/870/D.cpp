#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;
int n,a[N],b[N],w[2][N];
int ans[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"? "<<i<<" "<<i<<'\n';
        fflush(stdout);
        cin>>w[0][i];
    }
    for(int i=0;i<n;i++){
        cout<<"? 0 "<<i<<'\n';
        fflush(stdout);
        cin>>w[1][i];
    }
    int ansp=0;
    for(int val=0;val<n;val++){
        a[0]=val;
        for(int i=1;i<n;i++) a[i]=w[0][i]^w[1][i]^a[0];
        for(int i=0;i<n;i++) b[i]=a[i]^w[0][i];

        bool okay=1;
        for(int i=0;i<n;i++) okay&=a[b[i]]==i;
        if (okay){
            ansp++;
            for(int i=0;i<n;i++) ans[i]=a[i];
        }
    }
    cout<<"!\n"<<ansp<<'\n';
    for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
    fflush(stdout);
}