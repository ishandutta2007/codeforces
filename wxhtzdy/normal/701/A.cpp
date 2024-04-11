#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    vector<pair<int,int>> V;
    for(int i=0;i<n;i++)scanf("%i",&a[i]),V.pb({a[i],i+1});
    sort(V.begin(),V.end());
    int j=n-1;
    for(int i=0;i<n/2;i++)printf("%i %i\n",V[i].second,V[j].second),--j;
    return 0;
}