#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        vector<int> v;
        v.push_back(0);
        for(int i=1;i<n;i++){
            if(i==1||a[i]>a[i-1])v.back()+=1;
            else v.push_back(1);
        }
        int tmp1=0,tmp2=1,ans=0;
        for(int c:v){
            if(!tmp1)tmp1=tmp2,tmp2=0,ans++;
//            if(i==n-1||a[i]>a[i+1])tmp1--,tmp2++;
//            else tmp1--,tmp2+=2,i++;
            tmp1--,tmp2+=c;
        }
        printf("%i\n",ans);
    }
    return 0;
}