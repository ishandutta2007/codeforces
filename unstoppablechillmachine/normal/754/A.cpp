#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sc second

bool t,tr;
int n,a,k,k1,sum;
vector<pair<int,int> > Vec1;
vector <int> Vec;

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);


    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a;
        if (a!=0) tr=true;
        Vec.push_back(a);
        sum+=a;
    }

    if (!tr)
    {
        cout<<"NO";
        exit(0);
    }
    cout<<"YES"<<endl;

    if (sum!=0)
    {
        cout<<1<<endl;
        cout<<1<<" "<<n;
        exit(0);
    }

    cout<<2<<endl;

    k=0;
    while (Vec[k]==0)
    {
        k++;
    }

    cout<<1<<" "<<k+1<<endl;
    cout<<k+2<<" "<<n;
   return 0;
}