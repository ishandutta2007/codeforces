#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int sum=0;
        string s;
        cin>>s;
        int pd=0;
        for(char o:s){
            sum+=(o=='A'?1:-1);
            if(sum<0)pd=1;
        }
        printf(!pd&&(s.back()=='B')?"YES\n":"NO\n");
    }
    return  0;
}