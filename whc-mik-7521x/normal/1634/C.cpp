#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        int now=(n*k)>>1;
        if(now%k==0){
            cout<<"YES"<<endl;
            queue<int>s;
            for(int i=1;i<=k*n;i+=2)s.push(i);
            for(int i=2;i<=k*n;i+=2)s.push(i);
            for(int i=1;i<=n;i++){
                for(int o=1;o<=k;o++){
                    cout<<s.front()<<' ';
                    s.pop();
                }
                cout<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    return  0;
}