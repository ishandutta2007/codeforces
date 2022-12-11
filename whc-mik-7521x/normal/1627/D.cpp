#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ins[N],n,cnt,now;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){int x;scanf("%d",&x),ins[x]=1;}
    for(int i=1;i<=(int)1e6;i++){
        int now=0;
        for(int o=i;o<=(int)1e6;o+=i){
            if(ins[o]){
                now=__gcd(o,now);
            }
        }
        cnt+=now==i;
    }
    printf("%d",cnt-n);
    return  0;
}