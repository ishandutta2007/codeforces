#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
double ans;
int _,a,b;
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&a,&b);
        if(b==0){printf("%.10f\n",1.0);continue;}
        if(a==0){printf("%.10f\n",0.5);continue;}
        if(a>=4*b)
        {
            ans=(2.0*a*b-2.0*b*b)/(2.0*a*b);
            printf("%.10f\n",ans);
        }
        else
        {ans=(1.0*a*b+1.0*a*a/8.0)/(2.0*a*b);printf("%.10f\n",ans);}
    }
//    system("PAUSE");
}