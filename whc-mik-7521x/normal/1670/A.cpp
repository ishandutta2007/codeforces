#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt+=a[i]<0;
        }
        bool pd=0;
        for(int i=1;i<cnt;i++){
            if(abs(a[i])<abs(a[i+1]))pd=1;
        }
        for(int i=cnt+1;i<n;i++){
            if(abs(a[i])>abs(a[i+1]))pd=1;
        }
        puts(pd?"NO":"YES");
    }   
    return  0;
}