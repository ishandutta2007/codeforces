#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d%*c",&n,&m);
    char s[n+1];
    scanf("%s",s);
    pair<int,int> a[26];
    for(int i=0;i<26;i++)
        a[i]=make_pair(i,i);
    for(int i=0;i<m;i++)
    {
        char x,y;
        scanf("%*c%c%*c%c",&x,&y);
        swap(a[x-'a'].first,a[y-'a'].first);
    }
    sort(a,a+26);
    for(int i=0;i<n;i++)
        printf("%c",a[s[i]-'a'].second+'a');
}