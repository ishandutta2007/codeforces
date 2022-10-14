#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> v;
void ccc(int c){
    vector<int> b;
    while(c>0)b.pb(c%10),c/=10;
    reverse(b.begin(),b.end());
    for(auto cc:b)v.pb(cc);
}
int main(){
    int n;
    scanf("%i",&n);
    for(int i=1;i<=500;i++)ccc(i);
    printf("%i",v[n-1]);
}