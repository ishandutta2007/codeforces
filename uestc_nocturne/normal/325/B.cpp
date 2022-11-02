/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
LL pt[120],n,ans[1000100];
int ct;
int main()
{
    pt[0]=1;
    for(int i=1;i<=70;i++)pt[i]=pt[i-1]*2;
    while(cin>>n)
    {
        ct=0;
        for(int y=0;;y++)
        {
            if(pt[y]-1>n)break;
            //cout<<y<<endl;
            LL b=pt[y+1]-3;
            LL c=2*n;
            LL d=(LL)sqrt(4.0*c);
            LL lo=d-1,up=4*c+b;
            while(lo+1<up)
            {
                LL mid=lo/2+up/2+(lo%2+up%2)/2;
                //cout<<"Bs " << lo<<" "<<up<<endl;
                if(mid<=b)lo=mid;
                else if(mid+b>=4*c/(mid-b))up=mid;
                else lo=mid;
            }
            //cout<<b<<" "<<up<<endl;
            LL z=up;
            if(4*c/(z+b)<=(z-b)&&(z+b)*(z-b)==4*c)
            {
                LL w=z-b;
                if(w%2==0)
                {
                    LL x=w/2;
                    if(x%2==1)
                    ans[ct++]=pt[y]*x;
                    //cout<<x<<endl;
                    if(-b-z>0)
                    {
                        w=(-b-z)/2;
                        x=w/2;
                        if(x%2==1)
                        ans[ct++]=pt[y]*x;
                    }
                }
            }
        }
        sort(ans,ans+ct);
        if(ct==0)cout<<"-1"<<endl;
        else
        {
            for(int i=0;i<ct;i++)
            {
                cout<<ans[i];
                if(i==ct-1)cout<<endl;
                else cout<<" ";
            }
        }
    }
    return 0;
}