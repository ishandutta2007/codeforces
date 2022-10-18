#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int solve(int n,int pos)
{
//    cout<<pos<<" -> ";
    if(pos==n*(n-1)+1)
        return
//            cout<<"last -> ",
            1;
    int lo=1,hi=n-1;
    while(lo<hi)
    {
        int mi=(lo+hi+1)/2;
        int cnt=(2*n-mi)*(mi-1);
        if(pos>cnt)
            lo=mi;
        else
            hi=mi-1;
    }
    int mi=(lo+hi+1)/2;
    int cnt=(2*n-mi)*(mi-1);
    pos-=cnt;
//    cout<<mi<<" "<<cnt<<" "<<pos<<" -> ";
    if(pos%2==1)
        return mi;
    else
        return pos/2+mi;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        for(int i=l;i<=r;i++)
//            cout<<solve(n,i)<<"\n";
            cout<<solve(n,i)<<" ";
        cout<<"\n";
    }
}