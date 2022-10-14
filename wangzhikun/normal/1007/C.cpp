#include<bits/stdc++.h>
#define L long long
using namespace std;
const double eps=1e-7;
L n;
inline void orz(L a,L b,L c,L d,L e,L f);
inline void orz(L a,L b,L c,L d)
{
    L x,y;
    int p;
    x=(L)(a+0.2*(b-a)+eps);
    y=(L)(c+0.2*(d-c)+eps);
    cout<<x<<" "<<y<<endl;
    fflush(stdout);
    cin>>p;
    if(!p)
      return;
    if(p==1)
      orz(x+1,b,c,d);
    if(p==2)
      orz(a,b,y+1,d);
    if(p==3)
      orz(a,b,c,d,x-1,y-1);
}
inline void orz(L a,L b,L c,L d,L e,L f)
{
    if(a>e)
      {
       orz(a,b,c,f);
       return;
      }
    if(c>f)
      {
       orz(a,e,c,d);
       return;
      }
    L x,y;
    int p;
    x=(L)(a+0.8*(e-a)+eps);
    y=(L)(c+0.8*(f-c)+eps);
    cout<<x<<" "<<y<<endl;
    fflush(stdout);
    cin>>p;
    if(!p)
      exit(0);
    if(p==1)
      orz(x+1,b,c,d,e,f);
    if(p==2)
      orz(a,b,y+1,d,e,f);
    if(p==3)
      orz(a,b,c,d,x-1,y-1);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	orz(1,n,1,n);
	return 0;
}