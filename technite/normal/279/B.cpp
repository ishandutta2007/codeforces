#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t,k=0,j=1,sum=0,count=1,big=-1;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sum+=arr[k];
    if(n==1)
    {
        if(arr[k]>t)
            big=0;
        else
            big=1;
    }
    else
    {
        while(j<=n)
        {
            if(sum>t)
            {
                sum-=arr[k];
                k++;
            }
            else
            {
                if(j-k>big)
                big=j-k;
                sum+=arr[j];
                j++;
            }
        }
    }
    cout<<big<<endl;
    return 0;
}