#include <bits/stdc++.h>

using namespace std;

char S[300020];

int fnd(int l,int r){
    char cc = S[l];
    if(S[r]!=S[l])return 0;
    int pl = l,pr = r;
    while(S[pl+1] == cc && pl<=pr)pl++;
    if(pl == pr){
        if(l == r)return 0;
        return r-l+2;
    }else{
        while(S[pr-1] == cc)pr--;
        if(pl-l+1 + r-pr+1<3)return 0;
        return fnd(pl+1,pr-1);
    }
}

int main(){
    cin>>S;
    int n = strlen(S);
    cout<<fnd(0,n-1)<<endl;
    return 0;
}