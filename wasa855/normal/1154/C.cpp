#include<bits/stdc++.h>
using namespace std;
int a[]={1,2,3,1,3,2,1};
int fo[4];
int t[4];
int main()
{
    for(int i=1;i<=3;i++)
    {
        scanf("%d",&fo[i]);
    }
    int ans=0;
    for(int i=1;i<=7;i++)
    {
        int tmp=0;
        for(int j=1;j<=3;j++)
        {
            t[j]=fo[j];
        }
        for(int j=1;j<i;j++)
        {
            t[a[j]]++;
            tmp--;
        }
        int res=min(t[1]/3,min(t[2]/2,t[3]/2));
        tmp+=res*7;
        t[1]-=res*3;
        t[2]-=res*2;
        t[3]-=res*2;
        for(int j=1;j<=7;j++)
        {
            if(t[a[j]]!=0)
            {
                t[a[j]]--;
                tmp++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,tmp);
//        printf("%d %d\n",i,tmp);
    }
    cout<<ans<<endl;
    return 0;
}