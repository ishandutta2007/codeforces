#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct unit
{int x,y,p;
 double d;
};
struct unit a[2000];

int n,pp;
double mid;

int check()
{int f,s=0,i,j;
 
 s=pp;
 
 for(i=1;i<=n;i++)
 {if(a[i].d<=mid)
    s+=a[i].p;
  if(s>=1000000)
    break;
 }
 
 //cout<<mid<<" "<<s<<endl;
 
 if(s>=1000000)
   return 1;
 else
   return 0;
}

int main()
{int i,j;
 double t,w,ans=100000000;
 
 cin>>n>>pp;
 
 for(i=1;i<=n;i++)
 {cin>>a[i].x>>a[i].y>>a[i].p;
  a[i].d=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
 }
 
 //for(i=1;i<=n;i++) cout<<a[i].d<<endl;
 
 
 t=0;
 w=100000000;
 while(t<=w)
 {mid=(t+w)/2;

  //cout<<t<<" "<<w<<endl;

  if(check())
  {w=mid-0.0000001;
   ans=min(mid,ans);
  }
  else
   t=mid+0.0000001;
 }
 
 if(ans!=100000000)
   printf("%.7f\n",ans);
 else
   cout<<-1<<endl;
 
 return 0;
}