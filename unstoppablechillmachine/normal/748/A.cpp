#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ll long long
#define ld long double

int n,m,a,a1,a2;
vector <int> Vec;
set<int> st;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m>>a;
    a1=a/m/2;
    if (m*2*a1!=a) a1++;
    cout<<a1<<" ";
    a2=a%(m*2);
    if (a2==0) cout<<m<<" ";
    else
    if (a2%2==0)
    cout<<a2/2<<" ";
    else cout<<a2/2+1<<" ";


    if (a%2==0) cout<<"R";
    else cout<<"L";



    return 0;
}