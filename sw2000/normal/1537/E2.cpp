#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mod=1e9+7;
char b[N];
int n,k;
void o(int l){
    for(int i=1;k--;i=i%l+1)cout<<b[i];
    exit(0);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    cin>>n>>k>>b+1;
    cin>>b+1;
    int lb=strlen(b+1),l=1;
    for(int i=2,j=1;i<=lb;i++){
        if(b[i]>b[j])o(l);
        else if(b[i]==b[j])j++;
        else l=i,j=1;
    }
    o(l);
}