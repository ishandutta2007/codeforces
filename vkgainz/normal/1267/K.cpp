#include <bits/stdc++.h>
using namespace std;

int t;
long long factorial(int i){
    if(i==0) return 1;
    return factorial(i-1)*i;
}
void solve(long long k){
    int freq[21];
    memset(freq,0,sizeof(freq));
    int mod[21];
    memset(mod,-1,sizeof(mod));
    int i=2;
    while(k>0){
        freq[k%i]++;
        mod[i] = k%i;
        k/=i;
        i++;
    }
    i--;
    long long tot = 1;
    int num=freq[0];
    for(int j=2;j<=i;j++){
        num+=freq[j-1];
        tot*=num;
        num--;

        
    }
    for(int i=0;i<21;i++){
        tot/=factorial(freq[i]);
    }
    long long overcount = 1;
    if(freq[0]==0){
        overcount =0;
    }
    else{
        freq[0]--;
        num = freq[0];
        for(int j=2;j<i;j++){
            num+=freq[j-1];
            overcount*=num;
            num--;
        }
        for(int i=0;i<21;i++){
            overcount/=factorial(freq[i]);
        }
        tot-=overcount;
        
    }
    cout<< tot-1 << endl;
   
}
int main(){
    cin >> t;
    while(t--){
        long long k;
        cin >> k;
        solve(k);
    }
}