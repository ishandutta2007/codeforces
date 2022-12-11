#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int a[N],deg[N],h[N];
int main(){
        int n;
        cin>>n;
        for(int i=2;i<=n;i++){
                cin>>a[i];
                deg[a[i]]++;
        }
        for(int i=1;i<=n;i++) if (!deg[i]) h[a[i]]++;
        int ans=1;
        for(int i=1;i<=n;i++) if (deg[i]&&h[i]<3) ans=0;
        cout<<(ans?"Yes":"No");
}