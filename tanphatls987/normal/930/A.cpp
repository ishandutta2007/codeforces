#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,depth[N],h[N];
int pa[N];
int main(){
        cin>>n;
        for(int i=2;i<=n;i++) {
                cin>>pa[i];
                depth[i]=depth[pa[i]]+1;
        }
        for(int i=1;i<=n;i++) h[depth[i]]^=1;
        cout<<count(h,h+n+1,1);
}