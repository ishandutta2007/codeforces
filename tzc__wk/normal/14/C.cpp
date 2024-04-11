#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> M;
int main()
{
    int x1,y1,x2,y2;
    int cnt1=0,cnt2=0;
    for(int i=0;i<4;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cnt1+=(x1!=x2)&&(y1==y2);
        cnt2+=(x1==x2)&&(y1!=y2);
        M[make_pair(x1,y1)]++;
        M[make_pair(x2,y2)]++;
    }
    bool flag=(cnt1==2)&&(cnt2==2);
    for(map<pair<int,int>,int>::iterator i=M.begin();i!=M.end();i++)
        flag=flag&&(i->second==2);
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}