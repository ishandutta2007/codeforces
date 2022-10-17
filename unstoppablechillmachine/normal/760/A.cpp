#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sec second

struct coor
{
    int x,y;
};

struct graph
{
    int from,to,cost;
};


bool t;
queue <int> q;
set<int> st;
string s;
char ch;
vector <int> Vec;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},kol,m,sum,day,ans,n;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    kol=a[n];
    day=m;
    sum=0;
    while (sum<kol)
    {
        if (day==1 || !ans) ans++;
        if (day<7) day++;
        else
        {
            day=1;
        }
        sum++;
    }

    cout<<ans;



    return 0;
}