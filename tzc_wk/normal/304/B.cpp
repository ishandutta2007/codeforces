#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;
int month1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},month2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
long long sum=0;
bool leap(int n)
{
	if(n%4==0 && n%100!=0 or n%400==0)	return true;
	else return false;	
}
int y1,m1,d1,y2,m2,d2,i;
int q=0;
int main()
{
	scanf("%d:%d:%d",&y1,&m1,&d1);
	scanf("%d:%d:%d",&y2,&m2,&d2);
	if(y1>y2 or y1==y2&&m1>m2 or y1==y2&&m1==m2&&d1>d2)
	{
		swap(y1,y2);
		swap(m1,m2);
		swap(d1,d2);
	}
	if(leap(y2))
	{
            for(i=1;i<m2;i++)
			{
                sum+=month2[i];
            }
            sum+=d2;
    }
    else
	{
	    for(i=1;i<m2;i++)
		{
    	sum+=month1[i];
        }
            sum+=d2;
    }
        if(leap(y1)){
            for(i=1;i<m1;i++)
			{
               q+=month2[i];
            }
            q+=d1;
            sum=sum+366-q;
        }
		else
		{
            for(i=1;i<m1;i++)
			{
                q+=month1[i];
            }
            q+=d1;
            sum=sum+365-q;
        }
        for(i=y1+1;i<y2;i++)
		{
            if(leap(i))
			{
                sum+=366;
            }
			else
			{
                sum+=365;
            }
        }
        if(y1==y2)
		{
            if(leap(y1))
			{
                sum-=366;
            }
			else
			{
                sum-=365;
            }
        }
        printf("%d\n",sum);
    return 0;
}