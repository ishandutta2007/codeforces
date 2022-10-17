
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int cnt[200];
vector<char> v;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        v.clear();
        string s;
        cin>>s;
        for(int i=0;i<s.size();++i) cnt[s[i]]++,v.push_back(s[i]);
        int num = 0;
        sort(v.begin(),v.end());
        unique(v.begin(),v.end());
        for(int i='a';i<='z';++i) if(cnt[i]) num++;
        if(num==1)
        {
            cout << s << endl;
        }
        else if(num==2)
        {
            if(v[1]-v[0]==1) {cout<<"No answer"<<endl;continue;}
            cout << s << endl;
        }
        else if(num==3)
        {
            if(v[2]-v[1]==1&&v[1]-v[0]==1)
            {
                cout << "No answer" << endl;
                continue;
            }
            if(v[1]-v[0]==1)
            {
                for(int j=1;j<=cnt[v[0]];++j) cout<<v[0];
                for(int j=1;j<=cnt[v[2]];++j) cout<<v[2];
                for(int j=1;j<=cnt[v[1]];++j) cout<<v[1];
            }
            else
            {
                for(int j=1;j<=cnt[v[1]];++j) cout<<v[1];
                for(int j=1;j<=cnt[v[0]];++j) cout<<v[0];
                for(int j=1;j<=cnt[v[2]];++j) cout<<v[2];
            }
            cout << endl;
        }
        else
        {
            for(int i=1;i<num;i+=2)
            {
                for(int j=1;j<=cnt[v[i]];++j) cout<<v[i];
            }
            for(int i=0;i<num;i+=2)
            {
                for(int j=1;j<=cnt[v[i]];++j) cout<<v[i];
            }
            cout << endl;
        }
    }
}