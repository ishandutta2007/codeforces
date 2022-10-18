#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int n;
    cin>>n;
    string ex;
    getline(cin,ex);
    ex.clear();
    stack<bool>st;
    while(n--)
    {
        string s;
        getline(cin,s);
        while(s.back()==' '||s.back()==')'||s.back()=='"')
            s.pop_back();
        reverse(s.begin(),s.end());
        while(s.back()==' ')
            s.pop_back();
        if(s.size()<3)
            continue;
        if(s[s.size()-2]=='r') /// try
        {
            st.push(false);
//            cout<<"st.push(false)\n";
            continue;
        }
        else if(s[s.size()-2]=='h') /// throw
        {
            s.pop_back();
            s.pop_back();
            s.pop_back();
            s.pop_back();
            s.pop_back();
            while(s.back()==' '||s.back()=='(')
                s.pop_back();
            reverse(s.begin(),s.end());
            st.push(true);
            ex=s;
//            cout<<"st.push(true)\nex=\""<<ex<<"\"\n";
        }
        else if(s[s.size()-2]=='a') /// catch
        {
            s.pop_back();
            s.pop_back();
            s.pop_back();
            s.pop_back();
            s.pop_back();
            while(s.back()==' '||s.back()=='(')
                s.pop_back();
            reverse(s.begin(),s.end());
            int i=s.find(',');
            string a=s.substr(0,i),b=s.substr(i+1);
            while(a.back()==' ')
                a.pop_back();
            reverse(b.begin(),b.end());
            while(b.back()==' '||b.back()=='"')
                b.pop_back();
            reverse(b.begin(),b.end());
            if(st.top())
            {
//                cout<<a<<"\n";
                if(ex==a)
                    cout<<b,exit(0);
                else
                {
                    st.pop(),st.pop(),st.push(true);
//                    cout<<"st.pop(),st.pop(),st.push(true)\n";
                }
            }
            else
            {
                st.pop();
//                cout<<"st.pop()\n";
            }
        }
    }
    cout<<"Unhandled Exception";
}