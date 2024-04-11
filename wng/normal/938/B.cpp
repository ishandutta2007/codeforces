#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int nmax=1000000;
    int n,a;
    cin>>n;
    int maxs=0;
    for (int i=0;i<n;i++){
        cin>>a;
        maxs=max(maxs,min(a-1,nmax-a));
    }
    cout<<maxs<<endl;
}