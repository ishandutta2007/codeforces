#include<bits/stdc++.h>
using namespace std;

int n,k;
char s[300007],ans[300007];
bool ck(){
    for (int i=0;i<n;++i){
        if (s[i]<ans[i]) return 0;
        if (s[i]>ans[i]) return 1;
    }
    return 0;
}
int main(){
    cin>>n>>k>>s;
    for (int i=0;i<n;++i) ans[i]=s[i%k];
    if (!ck()){
        cout<<n<<"\n"<<ans<<endl;
    } 
    else{
        int t=k-1;
        while (s[t]=='9') s[t]='0', t--;
        s[t]++;
        cout<<n<<endl;
        for (int i=0;i<n;++i) cout<<s[i%k];
    }
    return 0;
}