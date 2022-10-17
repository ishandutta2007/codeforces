#include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sec second

ifstream in;
ofstream out;

string s;
set <int> st;
set<int>::iterator it;
int n,m,k,pos1,pos2,l,r,x,x1,sum;
vector<itn> Vec;
bool t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    if (n>10) cout<<n-2;
    else cout<<n+2;
    return 0;
}