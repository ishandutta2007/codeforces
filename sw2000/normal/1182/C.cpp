#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

struct A
{
    string word;
    char last;
    int len;
    int cnt=0;
}a[maxn];

struct P
{
    int a,b;
};

vector<int>v[5][maxn*10];
vector<P>p1,p2;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a[i].word;
        a[i].len=a[i].word.length();
        for(int j=0;j<a[i].len;j++)
        {
            if(a[i].word[j]=='a'||a[i].word[j]=='e'||a[i].word[j]=='i'||a[i].word[j]=='o'||a[i].word[j]=='u')
            {
                a[i].cnt++;
                a[i].last=a[i].word[j];
            }
        }
        if(a[i].last=='a')v[0][a[i].cnt].push_back(i);
        if(a[i].last=='e')v[1][a[i].cnt].push_back(i);
        if(a[i].last=='i')v[2][a[i].cnt].push_back(i);
        if(a[i].last=='o')v[3][a[i].cnt].push_back(i);
        if(a[i].last=='u')v[4][a[i].cnt].push_back(i);
    }

    for(int i=1;i<1e6;i++)
    {
        P tmp={-1,-1};
        for(int j=0;j<5;j++)
        {
            int len=v[j][i].size();
            if(len&1)
            {
                if(tmp.a==-1)tmp.a=v[j][i][len-1];
                else
                {
                    tmp.b=v[j][i][len-1];
                    p1.push_back(tmp);
                    tmp={-1,-1};
                }
                v[j][i].erase(v[j][i].begin()+len-1);
            }
        }
    }
    for(int i=0;i<1e6;i++)
    {
        for(int j=0;j<5;j++)
        {
            int len=v[j][i].size();
            P tmp;
            for(int k=0;k<len;k+=2)
            {
                p2.push_back({v[j][i][k],v[j][i][k+1]});
            }
        }
    }

    int len1=p1.size(),len2=p2.size();
    if(len1>=len2)
    {
        cout<<len2<<endl;
        for(int i=0;i<len2;i++)
        {
            cout<<a[p1[i].a].word<<' ';
            cout<<a[p2[i].a].word<<endl;
            cout<<a[p1[i].b].word<<' ';
            cout<<a[p2[i].b].word<<endl;
        }
    }
    else
    {
        cout<<len1+(len2-len1)/2<<endl;


        for(int i=0;i<len1;i++)
        {
            cout<<a[p1[i].a].word<<' ';
            cout<<a[p2[i].a].word<<endl;
            cout<<a[p1[i].b].word<<' ';
            cout<<a[p2[i].b].word<<endl;
        }
        for(int i=len1;i<len2-1;i+=2)
        {
            cout<<a[p2[i].a].word<<' ';
            cout<<a[p2[i+1].a].word<<endl;
            cout<<a[p2[i].b].word<<' ';
            cout<<a[p2[i+1].b].word<<endl;
        }
    }
	return 0;
}