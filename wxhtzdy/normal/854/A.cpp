#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n;
    scanf("%i",&n);
    for(int i=n/2;i>=1;i--){
        for(int j=i+1;j<=n-1;j++){
            if(i+j!=n)continue;
            bool ok=1;
            for(int k=2;k<=i;k++){
                if(i%k==0&&j%k==0)ok=0;
            }
            if(ok){printf("%i %i",i,j);return 0;}
        }
    }
}