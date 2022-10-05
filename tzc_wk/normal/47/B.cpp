#include <bits/stdc++.h>
using namespace std;
char x,y,t;
struct node{
    char c;
    int p;
}ans[4];
bool cmp(const node &a,const node &b){return a.p<b.p;}
int main()
{
    for(int i=1;i<=3;i++)
    {
        ans[i].c='A'+i-1;
        cin>>x>>t>>y;
        if(t=='>')  swap(x,y);
        ans[x-'A'+1].p++;
        ans[y-'A'+1].p+=2;
    }
    sort(ans+1,ans+4,cmp);
    if(ans[1].p==ans[2].p||ans[2].p==ans[3].p)
        {cout<<"Impossible";return 0;}
    cout<<ans[1].c<<ans[2].c<<ans[3].c;
    return 0;
}