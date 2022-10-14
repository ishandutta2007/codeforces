#include <bits/stdc++.h>
using namespace std;
/*
 1 -
 2 - 1
 3 - 3
 4 - 1 4
 7 - 1 6 7 - 13
 7 - 2 3 4 5 - 6 + 6 + 3 - 15
*/
// 59998
int main(){
    int n;
    scanf("%i",&n);
    if(n%4==0){
        printf("0\n%i ",n/2);
        for(int i=1;i<=n/4;i++)printf("%i ",i);
        for(int i=1;i<=n/4;i++)printf("%i ",n-i+1);
    }else{
        if(n%4==1){
            printf("1\n");
            int k=n/4;
            printf("%i ",k*2+1);
            for(int i=1;i<=k+1;i++)printf("%i ",i);
            for(int i=0;i<k;i++)printf("%i ",n-i);
        }else{
            if(n%4==2){
                printf("1\n");
                vector<long long> all;
                long long sum=0;
                int add=1;
                for(int i=1;i<=n;i+=add){
                    all.push_back(i);
                    sum+=i;
                    if(add==3)add=1;
                    else add=3;
                }
                printf("%i ",(int)all.size());
                for(int i:all)printf("%i ",i);
            }else{
                printf("0\n");
                printf("%i ",2*(n/4)+1);
                for(int i=1;i<=n/4;i++)printf("%i ",i);
                for(int i=0;i<=n/4;i++)printf("%i ",n-i);
            }
        }
    }
    return 0;
}