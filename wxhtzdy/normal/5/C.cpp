#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
char s[N];
int L[N],R[N],bal=0;
int main(){
    scanf("%s",&s);
    pair<int,int> ans={0,1};
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='(')L[++bal]=i;
        else if(bal>0){
            R[i]=i-L[bal]+1+R[L[bal--]-1];
            if(R[i]>ans.first)ans={R[i],1};
            else if(R[i]==ans.first)ans.second++;
        }
    }
    printf("%i %i",ans.first,ans.second);
    return 0;
}