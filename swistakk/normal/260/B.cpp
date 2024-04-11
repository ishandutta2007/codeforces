#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>
#define uint long long int
#define N 1000005
using namespace std;
int dni[15]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int w(char a)
{
    return int(a)-int('0');
}
bool cyf(char a)
{
    //cout<<int('0')<<" "<<int('a')<<" "<<int('9')<<" ";
    return (int(a)>=int('0') && int(a)<=int('9'));
}
char pro[N];
int odp[40][15][2020];
int main()
{
    // ios_base::sync_with_stdio(0);
    scanf("%s", pro);
    int dl=strlen(pro);
    //cout<<dl<<endl;
    //cout<<pro[dl-1]<<" "<<pro[dl]<<endl;
    
    for(int i=0; i<=dl-10; i++)
    {
        bool czy=true;
        czy= (czy && (pro[i+2]=='-' && pro[i+5]=='-'));
        //cout<<czy<<" zonk ";
        for(int j=0; j<=9; j++)
        {
            //cout<<"co jest? "<<j<<" ";
            //cout<<int(pro[i+j])<<" ";
            if(j!=2 && j!=5)
            {
                czy=(czy && cyf(pro[i+j]));
            }
        }
        //cout<<czy<<endl;
        int d=10*w(pro[i])+w(pro[i+1]);
        int m=10*w(pro[i+3])+w(pro[i+4]);
        int y=1000*w(pro[i+6])+100*w(pro[i+7])+10*w(pro[i+8])+w(pro[i+9]);
        if(czy && m>=1 && m<=12 && d>=1 && d<=dni[m] && y>=2013 && y<=2015)
        {
            odp[d][m][y]++;
            //cout<<d<<" "<<m<<" "<<y<<endl;
        }
    }
    int md, mm, my, mw=0;
    for(int i=1; i<=31; i++)
    {
        for(int j=1; j<=12; j++)
        {
            for(int k=2013; k<=2015; k++)
            {
                if(odp[i][j][k]>mw)
                {
                    mw=odp[i][j][k];
                    md=i;
                    mm=j;
                    my=k;
                }
            }
        }
    }
    if(md<=9)
    {
        cout<<"0";
    }
    cout<<md;
    cout<<"-";
    if(mm<=9)
    {
        cout<<"0";
    }
    cout<<mm<<"-"<<my<<endl;
    
    return 0;
}