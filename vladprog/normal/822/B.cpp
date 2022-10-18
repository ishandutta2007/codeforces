#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char c1[n+1],c2[m+1];
    scanf("%s%s",&c1,&c2);
    string s(c1),t(c2);
    vector<int> a;
    for(int i=0;i<=m-n;i++)
    {
        vector<int> ta;
        for(int j=0;j<n;j++)
            if(s[j]!=t[i+j])
                ta.push_back(j+1);
        if(i==0||ta.size()<a.size())
            a=ta;
    }
    printf("%d\n",a.size());
    for(vector<int>::iterator i=a.begin();
        i!=a.end();i++)
        printf("%d ",*i);
}