#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
struct node
{
    int x,y;
}aa[250010];
int n,m;
int main()
{
    cin>>n;
    string a,b;
    cin>>a>>b;
    map<char,vector<int>>m1,m2;
    for(int i=0;i<n;i++)
    {
        m1[a[i]].push_back(i+1);
        m2[b[i]].push_back(i+1);
    }
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        char ch='a'+i;
    while(m1[ch].size()!=0&&m2[ch].size()!=0)
    {
        aa[cnt].x=m1[ch][m1[ch].size()-1];
        aa[cnt++].y=m2[ch][m2[ch].size()-1];
        m1[ch].pop_back();
        m2[ch].pop_back();
    }
    }
    char s='?';
    while(!m1[s].empty())
    {
        int flag=0;
        for(int i=0;i<26;i++)
        {
            char ch='a'+i;
            if(m2[ch].size()!=0)
            {
                flag=1;
                aa[cnt].x=m1[s][m1[s].size()-1];
                aa[cnt++].y=m2[ch][m2[ch].size()-1];
                m1[s].pop_back();
                m2[ch].pop_back();
            }
            if(m1[s].size()==0)
                break;
        }
        if(flag==0)
            break;
    }
    while(!m2[s].empty())
    {
        int flag=0;
        for(int i=0;i<26;i++)
        {
            char ch='a'+i;
            if(m1[ch].size()!=0)
            {
                flag=1;
                aa[cnt].x=m1[ch][m1[ch].size()-1];
                aa[cnt++].y=m2[s][m2[s].size()-1];
                m1[ch].pop_back();
                m2[s].pop_back();
            }
            if(m2[s].size()==0)
                break;
        }
        if(flag==0)
            break;
    }
    while(m2[s].size()!=0&&m1[s].size()!=0)
    {
        aa[cnt].x=m1[s][m1[s].size()-1];
        aa[cnt++].y=m2[s][m2[s].size()-1];
        m1[s].pop_back();
        m2[s].pop_back();
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<aa[i].x<<' '<<aa[i].y<<endl;
    }
    return 0;
}