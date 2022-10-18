#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

string str(int len,char ch)
{
    return string("('")+ch+"'*"+to_string(len)+") ";
}

//#define string str

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    if(n==2)
        cout<<-1,exit(0);
    int m=1;
    while(m*m<n)
        m++;
    if(m*m-n==2)
    {
        m++;
        cout<<m<<"\n";
        cout<<"o"<<string(m-1,'.')<<"\n";
        cout<<string(m-3,'o')<<"..."<<"\n";
        cout<<string(m-3,'o')<<"..."<<"\n";
        for(int i=0;i<m-4;i++)
            cout<<string(m-1,'o')<<"."<<"\n";
        cout<<string(m,'o')<<"\n";
    }
    else
    {
        int k=m*m-n;
        cout<<m<<"\n";
        if(k)
            cout<<string(m-(k+1)/2,'o')<<string((k+1)/2,'.')<<"\n";
        for(int i=0;i<(k-1)/2;i++)
            cout<<string(m-2,'o')<<"o."[i==0&&k%2==0]<<"."<<"\n";
        for(int i=0;i<m-(k+1)/2;i++)
            cout<<string(m,'o')<<"\n";
    }
}