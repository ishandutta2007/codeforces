#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long getdate(int y,int m,int d)
{
    int yy=y;
    long long day=0;
    y--;
    day+=y/400*146097;
    y%=400;
    day+=y/100*36524;
    y%=100;
    day+=y/4*1461;
    y%=4;
    day+=y*365;
    if (m>1) day+=31;
    if (m>2) day+=28;
    if (m>3) day+=31;
    if (m>4) day+=30;
    if (m>5) day+=31;
    if (m>6) day+=30;
    if (m>7) day+=31;
    if (m>8) day+=31;
    if (m>9) day+=30;
    if (m>10) day+=31;
    if (m>11) day+=30;
    day+=d;
    if (m>2)
    {
        if (yy%4==0) day++;
        if (yy%100==0) day--;
        if (yy%400==0) day++;
    }
    return day;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int y1,m1,d1,y2,m2,d2;
    scanf("%d:%d:%d",&y1,&m1,&d1);
    scanf("%d:%d:%d",&y2,&m2,&d2);
    long long day1=getdate(y1,m1,d1);
    long long day2=getdate(y2,m2,d2);
    day1-=day2;
    if (day1<0) day1=-day1;
    cout<<day1<<endl;
    return 0;
}