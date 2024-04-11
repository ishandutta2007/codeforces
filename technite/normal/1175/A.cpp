#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int n,k,count=0;
        cin>>n>>k;
        long long i=n;
        while(i>0){
            if(i%k==0){
                count++;
                i=i/k;
            }
            else{
                count+=i%k;
                i=i-i%k;
                
            }
        }
        cout<<count<<endl;
    }
}