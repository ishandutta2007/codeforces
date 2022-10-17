#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;

int main()
{
    string s;
    cin>>s;
    string ans;
    int i=0,j=s.size()-1;
    if(s.size()%2)
    {
        while(i<j)
        {
            ans+=s[i];
            ans+=s[j];
            i++,j--;
        }
        ans+=s[i];
    }
    else
    {
        while(i<j)
        {
            ans+=s[j];
            ans+=s[i];
            i++,j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}