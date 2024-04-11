#include <bits/stdc++.h>

using namespace std;

int main()
{
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int t;
    for(int i=0;i<n;++i)
    {
        cin>>t;
        a[i]=t;
    }
    int s1=0;
    int s2=0;
    vector <int> h1;
    vector <int> h2;
    for(int i=0;i<n;i+=2)
    {
        h1.push_back(s1);
        s1+=a[i];
    }
    h1.push_back(s1);
    for(int i=1;i<n;i+=2)
    {
        h2.push_back(s2);
        s2+=a[i];
    }
    h2.push_back(s2);
    int y=0;
    for(int i=0;i<n;++i)
    {
        if(i%2==1)
        {
            if((2*h1[(i+1)/2]+h2[h2.size()-1])==(2*h2[(i/2)]+h1[h1.size()-1]+a[i]))
            {
                ++y;
            }
        }
        if(i%2==0)
        {
            if((2*h1[i/2]+h2[h2.size()-1]+a[i])==(2*h2[(i/2)]+h1[h1.size()-1]))
            {
                ++y;
            }
        }
    }
    cout<<y<<endl;
    return 0;
}