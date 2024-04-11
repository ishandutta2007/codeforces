#include <bits/stdc++.h>
using namespace std;
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int d,m,y;
int tf(int d1,int m1,int y1)
{
    if(m1<1||m1>12||d1<1||d1>md[m1]+(m1==2&&y1%4==0)?1:0)
    return 0; 
    return (y1+18<y||y1+18==y&&m1<m||y1+18==y&&m1==m&&d1<=d); 
}
int main()
{
    int D,M,Y;
    scanf("%d.%d.%d",&d,&m,&y);
    scanf("%d.%d.%d",&D,&M,&Y);
    if(tf(D,M,Y)||tf(D,Y,M)||tf(M,D,Y)||tf(M,Y,D)||tf(Y,D,M)||tf(Y,M,D))
    	cout<<"YES"<<endl;
    else
    	cout<<"NO"<<endl;
    return 0;
}