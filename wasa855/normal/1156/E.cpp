#include<bits/stdc++.h>
using namespace std;
#define N 200005
int a[N];
int b[N];
int l[N],r[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    stack<int> s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[i]>a[s.top()]) s.pop();
        if(s.empty()) l[i]=1;
        else l[i]=s.top()+1;
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[i]>a[s.top()]) s.pop();
        if(s.empty()) r[i]=n;
        else r[i]=s.top()-1;
        s.push(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
//		printf("%d %d\n",l[i],r[i]);
        if((i-l[i]+1)>(r[i]-i+1))
        {
            for(int j=i+1;j<=r[i];j++)
            {
                if(b[a[i]-a[j]]>=l[i]&&b[a[i]-a[j]]<i) ans++;
            }
        }
        else
        {
            for(int j=l[i];j<i;j++)
            {
                if(b[a[i]-a[j]]>i&&b[a[i]-a[j]]<=r[i]) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

// efaiubjbnsdj