#include<bits/stdc++.h>
using namespace std;
int t,a[100];
int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==3){
            puts("3 2 1");
            puts("1 3 2");
            puts("3 1 2");
        }
        else if(n==4){
            puts("4 1 3 2");
            puts("1 2 4 3");
            puts("3 4 1 2");
            puts("2 4 1 3");
        }
        else{
            int now=n-n/2;
            vector<int>v;
            for(int i=1;i<=now;i++)v.push_back(i);
            for(int i=1;i<=n;i++){
                for(auto it:v)printf("%d ",it+n/2);
                for(int o=n/2;o>=1;o--)printf("%d ",o);
                next_permutation(v.begin(),v.end());
                puts("");
            }
        }
    }
    return  0;
}