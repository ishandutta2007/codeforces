#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int mx=0,sx=0;
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            if(a>=mx)sx=mx,mx=a;
            else if(a>=sx)sx=a;
        }
        cout<<sx+mx<<endl;
    }
    return  0;
}