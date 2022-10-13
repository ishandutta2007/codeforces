#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> f;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int freq[200001];
void modify(int x,int y){
    for(int i=1;i<=sqrt(x);i++){
        if(x%i==0){
            if(i*i==x){
                freq[i]+=y;
            }
            else{
                freq[i]+=y;
                freq[x/i]+=y;
            }
        }
    }
}
int main(){
    int n; 
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        f[a[i]]++;
    }
    for(auto &it : f){
        modify(it.first,it.second);
    }
    ll prod =1;
    for(int i=1;i<=200000;i++){
        if(freq[i]>=(n-1)){
            prod = prod/(gcd(prod,i))*i;
        }
    }
    printf("%llu",prod);
}