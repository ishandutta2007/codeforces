#include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sec second

string s;
set<string> st1,st2;
set<string>:: iterator it,it2;
int n,m;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        st1.insert(s);
    }

    for (int i=1;i<=m;i++)
    {
        cin>>s;
        st2.insert(s);
    }

    for (int i=1;i<=n+m+1;i++)
    {
        if (i%2==1)
        {
            if (st1.size()==0)
            {
                cout<<"NO";
                exit(0);
            }
            it=st1.begin();
            while (it!=st1.end() && st2.find(*it)==st2.end()) it++;
            if (it==st1.end())
            {
                st1.erase(st1.begin());
            }
            else
            {
                it2=st2.find(*it);
                st2.erase(it2);
                st1.erase(it);
            }
        }

        else
         {
            if (st2.size()==0)
            {
                cout<<"YES";
                exit(0);
            }
            it=st2.begin();
            while (it!=st2.end() && st1.find(*it)==st1.end()) it++;
            if (it==st2.end())
            {
                st2.erase(st2.begin());
            }
            else
            {
                it2=st1.find(*it);
                st1.erase(it2);
                st2.erase(it);
            }
        }
        //cout<<st1.size()<<" "<<st2.size()<<endl;
    }
    return 0;
}