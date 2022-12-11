#include <bits/stdc++.h>

using namespace std;

const int N=2e3+10;
int n,m,a[N],h[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]<=m) h[a[i]]++;
    }
    int ansv=n/m,ansc=0;
    for(int i=1,j=1;i<=n;i++){
        while (j<=m&&h[j]>=ansv) j++;
        if (j>m) break;
        if (a[i]>m||h[a[i]]>ansv){
            if (a[i]<=m) h[a[i]]--;
            a[i]=j;
            h[j]++;
            ansc++;
        }
    }
    cout<<ansv<<" "<<ansc<<'\n';
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}