#include <bits/stdc++.h>
#pragma optimize("O3");

#define x first
#define y second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n;
    cin>>n;
    string a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
        if(a[i].size()==s.size())
        {
            int flag=0;
            for(int j=0; j<s.size(); j++)
            {
                if(toupper(s[j])==toupper(a[i][j]))
                    flag++;
                if((char)toupper(s[j])=='L' && (char)toupper(a[i][j])=='I')
                    flag++;
                if((char)toupper(a[i][j])=='L' && (char)toupper(s[j])=='I')
                    flag++;
                if((char)toupper(s[j])=='O' && a[i][j]=='0')
                    flag++;
                if((char)toupper(a[i][j])=='O' && s[j]=='0')
                    flag++;
                if((char)toupper(s[j])=='L' && a[i][j]=='1')
                    flag++;
                if((char)toupper(a[i][j])=='L' && s[j]=='1')
                    flag++;
                if((char)toupper(s[j])=='I' && a[i][j]=='1')
                    flag++;
                if((char)toupper(a[i][j])=='I' && s[j]=='1')
                    flag++;
            }
            if(flag==s.size())
            {
                cout<<"No\n";
                return 0;
            }
        }
    cout<<"Yes\n";
}