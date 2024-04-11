#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
int n,x[N],w[N];
vector<pair<int,int>> A;
bool cmp(pair<int,int> a,pair<int,int> b){return a.first+a.second<b.first+b.second;}
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i %i",&x[i],&w[i]),A.pb({x[i],w[i]});
    sort(A.begin(),A.end(),cmp);
    int lst=0,ans=1;
    for(int i=1;i<n;i++)if(abs(A[i].first-A[lst].first)>=A[i].second+A[lst].second)lst=i,ans++;
    printf("%i",ans);
    return 0;
}