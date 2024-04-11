#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
std::set<int>W,H;
std::multiset<int>mw,mh;
int w,h,n;
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>w>>h>>n;
    W.insert(0);
    W.insert(w);
    H.insert(0);
    H.insert(h);
    mw.insert(w);
    mh.insert(h);
    for(register int i=1;i<=n;i++)
    {
        char c;
        int x;
        std::cin>>c>>x;
        if(c=='H')
        {
            H.insert(x);
            int a=*(--H.find(x)),b=*(++H.find(x));
            mh.erase(mh.find(b-a));
            mh.insert(x-a);
            mh.insert(b-x);
        }
        if(c=='V')
        {
            W.insert(x);
            int a=*(--W.find(x)),b=*(++W.find(x));
            mw.erase(mw.find(b-a));
            mw.insert(x-a);
            mw.insert(b-x);
        }
        printf("%lld\n",(long long)*mw.rbegin()**mh.rbegin());
    }
    return 0;
}