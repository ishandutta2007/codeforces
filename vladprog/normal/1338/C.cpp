#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int n=3*q;
        cin>>n;
        int x=(n-1)/3+1;
        int y=(n-1)%3+1;
//        cout<<n<<" -> "<<x<<" "<<y<<" -> ";
        int sub=1;
        while(true)
        {
            if(x<=sub)
                break;
            x-=sub;
            sub*=4;
        }
//        cout<<x<<" "<<sub<<" | ";
        int a=sub+x-1;
//        cout<<a<<" ";
        int d=0;
        x--;
        for(int i=60;i>=0;i-=2)
        {
            int pw=1ll<<i;
            int r=x/pw%4;
//            cout<<"("<<i<<","<<r<<","<<pw<<")";
            if(r==2)
                d+=pw;
            if(r==3)
                d+=5*pw;
        }
//        cout<<d<<" ";
        int b=2*a-d;
        int c=a^b;
//        cout<<a<<" "<<b<<" "<<c<<" ";
//        cout<<endl;
        if(y==1)
            cout<<a<<"\n";
        else if(y==2)
            cout<<b<<"\n";
        else
            cout<<c<<"\n";
    }
}