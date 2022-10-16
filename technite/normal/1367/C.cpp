#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        k+=1;
        string s;
        cin>>s;
        vector<int> one;
        one.push_back(-k);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') one.push_back(i);
        }
        one.push_back(n-1+k);
        int count=0;
        for (int i=0;i<one.size()-1;i++)
        {
            count+= max(0,((one[i+1]-one[i])/k)-1);
        }
        cout<<count<<"\n";
    }
}