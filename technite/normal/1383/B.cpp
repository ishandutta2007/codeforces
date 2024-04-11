#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n,0);
        vector<int> cnt(33,0);
        int high=0;bool ans=true;
        for(int i=0;i<n;i++) 
        {
            cin>>v[i];
            int j=0;
            int a=v[i];
            while(a)
            {
                if(a&1) cnt[j]++;
                j++;
                a/=2;
            }
        }
        for(int i=0;i<33;i++)
        {
            if(cnt[i]%2) {ans=false;high=max(high,i);}
        }
        if(ans)
        {
            cout<<"DRAW"<<'\n';
            continue;
        }
        int one=0,zero=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]&(1<<high)) one++;
            else zero++;
        }
        if(zero%2==0&&one%4==3)
        {
            cout<<"LOSE"<<'\n';
        }
        else cout<<"WIN"<<'\n';

    }
}