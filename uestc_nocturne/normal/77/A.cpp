#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef __int64 LL;
string ch,name[120];
const LL ooo=100000000;
const LL oo=ooo*ooo;
int map[120][120],ct[10],cs[120],ma,i,j,t;
int n,id1,id2;LL va[120],c[120],mid;
int main()
{
    while(~scanf("%d",&n))
    {
        t=0;
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
        {
            cin>>ch;
            bool dn=false;
            for(j=0;j<t;j++)
            {
                if(ch==name[j])
                {dn=true;id1=j;break;}
            }
            if(!dn){id1=t;name[t++]=ch;}
            cin>>ch;
            cin>>ch;
            dn=false;
            for(j=0;j<t;j++)
            {
                if(ch==name[j])
                {dn=true;id2=j;break;}
            }
            if(!dn){id2=t;name[t++]=ch;}
            map[id1][id2]=1;
        }
        for(i=0;i<3;i++)
        cin>>va[i];
        mid=oo;ma=0;
        for(cs[0]=0;cs[0]<3;cs[0]++)
        for(cs[1]=0;cs[1]<3;cs[1]++)
        for(cs[2]=0;cs[2]<3;cs[2]++)
        for(cs[3]=0;cs[3]<3;cs[3]++)
        for(cs[4]=0;cs[4]<3;cs[4]++)
        for(cs[5]=0;cs[5]<3;cs[5]++)
        for(cs[6]=0;cs[6]<3;cs[6]++)
        {
            memset(ct,0,sizeof(ct));
            for(i=0;i<7;i++)
            ct[cs[i]]++;
            bool can=true;
            for(i=0;i<3;i++)
            if(ct[i]==0){can=false;break;}
            if(!can)continue;
            for(i=0;i<3;i++)c[i]=va[i]/(LL)ct[i];
            sort(c,c+3);
            int te=0;
            for(i=0;i<7;i++)
            for(j=0;j<7;j++)
            if(cs[i]==cs[j]&&map[i][j]==1)te++;
            if(c[2]-c[0]<mid||(c[2]-c[0]==mid&&te>ma))
            {mid=c[2]-c[0];ma=te;}
        }
        cout<<mid<<" "<<ma<<endl;
    }
 //   system("PAUSE");
}