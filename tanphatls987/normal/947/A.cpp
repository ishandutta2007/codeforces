#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int f[N],t[N];
void prepare(){
        for(int i=2;i<N;i++) if (!t[i]){
                t[i]=1;
                for(int j=i+i;j<N;j+=i) t[j]=i;
        }
}
int main(){
        prepare();

        int n;
        cin>>n;
        int ans=n;
        for(int i=n-t[n]+1;i<=n;i++)  {
                ans=min(ans,i-t[i]+1);
        }
        cout<<ans;
}