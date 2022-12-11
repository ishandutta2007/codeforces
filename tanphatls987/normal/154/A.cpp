#include <bits/stdc++.h>

using namespace std;

const int alp=27;
string s;
int f[2][alp],a[alp][alp];
int main(){
    int k;
    cin>>s>>k;
    while (k--){
        string tmp;
        cin>>tmp;
        a[tmp[0]-'a'+1][tmp[1]-'a'+1]=1;
        a[tmp[1]-'a'+1][tmp[0]-'a'+1]=1;
    }
    int n=s.length();
    fill(f[0]+1,f[0]+alp,n+1);
    for(int i=0;i<n;i++){
        int cur=i&1,last=cur^1;
        int pos=s[i]-'a'+1;
        for(int j=0;j<alp;j++) f[last][j]=f[cur][j]+1;
        for(int j=0;j<alp;j++)
            if (!a[pos][j]) f[last][pos]=min(f[last][pos],f[cur][j]);
//        for(int j=0;j<alp;j++) cout<<f[last][j]<<" \n"[j==alp-1];
    }
    cout<<*min_element(f[n&1],f[n&1]+alp);
}