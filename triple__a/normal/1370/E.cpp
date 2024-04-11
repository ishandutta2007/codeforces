#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+7;
string s[2];
int a[maxn];
int n;
int main(){
    cin>>n;
    cin>>s[0]>>s[1];
    for (int i=1;i<=n;++i){
        a[i]=a[i-1];
        if (s[0][i-1]=='1'&&s[1][i-1]=='0') a[i]++;
        if (s[0][i-1]=='0'&&s[1][i-1]=='1') a[i]--;
    }
    int mx=0,mn=0;
    for (int i=1;i<=n;++i) mx=max(mx,a[i]), mn=min(mn,a[i]);
    if (a[n]==0) cout<<mx-mn;
    else cout<<-1;
}