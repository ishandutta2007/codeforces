#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    if(n>26){printf("-1");return 0;}
    int cnt[27],sum=0;
    for(int i=0;i<27;i++)cnt[i]=0;
    for(int i=0;i<n;i++)cnt[(int)(s[i]-'a')]++;
    for(int i=0;i<27;i++)if(cnt[i]>1)sum+=cnt[i]-1;
    cout<<sum;
}