#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
void factorize(long long n,vpi&v) 
{ 
    int count = 0; 
    while (!(n % 2)) { 
        n >>= 1;  
        count++; 
    } 
  
    if (count) 
        v.push_back(make_pair(2,count)); 
  
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            v.push_back(make_pair(i,count));
    } 
  
    if (n > 2) 
        v.push_back(make_pair(n,1));
} 
int main()
{
    int n;
    cin>>n;
    vpi v;
    factorize(n,v);
    if(v.size()==1) return cout<<"NO"<<'\n',0;
    else
    {
        int b1=pow(v[0].F,v[0].S);
        int b2=n/b1;
        int a1,a2;
        for(int i=1;i<b1;i++)
        {
            if((i*b2+1)%b1==0)
            {
                a1=i;
                break;
            }
        }
        a2=(n-1-a1*b2)/b1;
        cout<<"YES"<<'\n';
        cout<<2<<'\n';
        cout<<a1<<" "<<b1<<'\n';
        cout<<a2<<" "<<b2<<'\n';
    }
}