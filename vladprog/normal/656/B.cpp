#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int N=720720;
const double D=N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int m[n],r[n];
    for(int i=0;i<n;i++)
        cin>>m[i];
    for(int i=0;i<n;i++)
        cin>>r[i];
    set<int>s;
    for(int i=0;i<N;i++)
        for(int j=0;j<n;j++)
            if(i%m[j]==r[j])
                s.insert(i);
    cout<<s.size()/D;
}