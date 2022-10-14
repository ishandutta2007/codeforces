#include <bits/stdc++.h>
using namespace std;
int Solve(vector<int> a,int bit){
    if((int)a.size()<2)return (int)a.size();
    vector<int> bit0,bit1;
    for(int c:a){
        if(c&(1<<bit))bit1.push_back(c);
        else bit0.push_back(c);
    }
    if(bit0.size()==0)return Solve(bit1,bit-1);
    if(bit1.size()==0)return Solve(bit0,bit-1);
    return 1+max(Solve(bit0,bit-1),Solve(bit1,bit-1));
}
int main(){
    int n;scanf("%i",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    printf("%i",n-Solve(a,30));
    return 0;
}