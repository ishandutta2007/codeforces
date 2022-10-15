#include<bits/stdc++.h>
using namespace std;

const int maxn=2007;
bool lamp[maxn];
bool suppose[maxn];
int n,sum=0;
int main(){
    cin>>n;
    int mx=0,k=1;
    for (int i=1;i<=n;++i){
        int res=n-(n-1)/i-i;
        if (res>mx){
            mx=res;
            k=i;
        }
    }
    for (int i=0;i<n;++i){
        if (i%k==0) suppose[i]=0;
        else suppose[i]=1;
    }
    auto f=[&](){
        vector<int> ask;
        ask.clear();
        for (int i=0;i<n;++i){
            if (!lamp[i]&&suppose[i]) ask.push_back(i),lamp[i]=1;
            if (ask.size()==k) break;
        }
        cout<<k<<" ";
        for (auto c:ask){
            cout<<c+1<<" ";
        }
        sum+=k;
        cout<<endl;
    };
    auto g=[&](){
        int x;
        cin>>x;
        x--;
        for (int i=0;i<k;++i){
            if (lamp[(i+x)%n]) lamp[(i+x)%n]=0, sum--;
        }
    };
    while (1){
        if (sum>=mx) break;
        f();
        g();
    }
    cout<<"0"<<endl;
    return 0;
}