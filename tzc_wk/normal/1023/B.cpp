#include <iostream>
using namespace std; main(){long long n,k;cin>>n>>k;cout<<max((long long)0,(k-1)/2-max((long long)0,k-1-n))<<endl;}