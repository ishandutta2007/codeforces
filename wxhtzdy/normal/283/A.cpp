#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int a[N];
int main(){
    int n,t,x,y,sz=1;
    scanf("%i",&n);
    double sum=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        scanf("%i",&t);
        if(t==1){
            scanf("%i %i",&x,&y);
            x=min(x,n);
            sum+=x*y;
            mp[x]+=y;
        }else if(t==2){
            scanf("%i",&x);
            sz++,a[sz]=x;
            sum+=a[sz];
        }else{
            sum-=(a[sz]+mp[sz]);
            mp[sz-1]+=mp[sz],mp[sz]=0;
            sz--;
        }
        printf("%.6lf\n",sum/sz);
    }
    return 0;
}