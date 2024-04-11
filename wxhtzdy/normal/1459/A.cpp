#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        char a[n],b[n];scanf("%s %s",&a,&b);
        //sort(a,a+n);sort(b,b+n);
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(a[i]>b[i])cnt1++;
            if(a[i]<b[i])cnt2++;
        }
        if(cnt1==cnt2)printf("EQUAL\n");
        else{
            if(cnt1>cnt2)printf("RED\n");
            else printf("BLUE\n");
        }
    }
    return 0;
}