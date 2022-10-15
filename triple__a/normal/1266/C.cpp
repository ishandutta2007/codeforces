#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int c,w;
    cin>>c>>w;
    if (c==1&&w==1){ cout<<0; return 0;}
    if (w==1){
        for (int i=1;i<=c;++i) cout<<i+1<<endl;
        return 0;
    }
    for (int i=1;i<=c;++i){
        for (int j=1;j<=w;++j){
            cout<<(j+c)*i<<" ";
        }
        cout<<endl;
    }
    return 0;
}