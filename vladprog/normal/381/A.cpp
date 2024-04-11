#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    deque<int> q;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        q.push_back(a);
    }
    int a=0,b=0;
    for(int i=1;i<=n;i++)
        if(i%2)
            if(q.front()>q.back())
                a+=q.front(),q.pop_front();
            else
                a+=q.back(),q.pop_back();
        else
            if(q.front()>q.back())
                b+=q.front(),q.pop_front();
            else
                b+=q.back(),q.pop_back();
    printf("%d %d",a,b);
}