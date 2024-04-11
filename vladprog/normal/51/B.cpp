#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> ans;
string s;

void solve(int l,int r)
{
//    cout<<l<<" "<<r<<"\n";
    int d=0,res=0,p=l;
    for(int i=l;i<=r;i++)
        if(s[i]=='(')
        {
            if(d==2)
                p=i+1;
            d++;
        }
        else if(s[i]==')')
        {
            d--;
            if(d==0)
            {
                if(res)
                    ans.push_back(res);
                res=0;
            }
            else if(d==2)
                solve(p,i-1),res++;
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s0;
    string t;
    while(cin>>t)
        s0+=t;
    vector<int> sz;
    for(int i=0;i<s0.size();i++)
        if(s0.substr(i,7)=="<table>")
            s+='(',i+=6;
        else if(s0.substr(i,4)=="<tr>")
            s+='(',i+=3;
        else if(s0.substr(i,4)=="<td>")
            s+='(',i+=3;
        else if(s0.substr(i,8)=="</table>")
            s+=')',i+=7;
        else if(s0.substr(i,5)=="</tr>")
            s+=')',i+=4;
        else if(s0.substr(i,5)=="</td>")
            s+=')',i+=4;
        else
            s+=s0[i];
//    for(int i=0;i<s.size();i++)
//        cout<<i%10;
//    cout<<"\n";
//    cout<<s<<"\n";
    solve(0,s.size()-1);
    sort(ans.begin(),ans.end());
    for(int x:ans)
        cout<<x<<" ";
}