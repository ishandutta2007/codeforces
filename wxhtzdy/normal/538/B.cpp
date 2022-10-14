#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n>0){
        int x=n,s=0,cc=1;
        while(x>0){
            if(x%10>0)s+=cc;
            x/=10,cc*=10;
        }
        v.push_back(s);
        n-=s;
    }
    printf("%i\n",(int)v.size());
    for(auto c:v)printf("%i ",c);
}