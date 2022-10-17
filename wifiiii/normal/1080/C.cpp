#include<iostream>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        long long m,n,black,white;
        cin>>n>>m;
        if(n%2 && m%2) white=m*n/2+1,black=m*n/2;
        else if(n%2 && m%2==0) white=m*n/2,black=m*n/2;
        else if(n%2==0 && m%2) white=m*n/2,black=m*n/2;
        else if(n%2==0 && m%2==0) white=m*n/2,black=m*n/2;
        long long x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        long long sw = (y2-y1+1)*(x2-x1+1);
        long long x3,y3,x4,y4;
        cin>>x3>>y3>>x4>>y4;
        long long sb = (y4-y3+1)*(x4-x3+1);
        if(x3>x2||x4<x1||y4<y1||y3>y2) //
        {
            if(sw%2==0) white+=sw/2,black-=sw/2;
            else if((x1+y1)%2) white+=sw/2+1,black-=sw/2+1;
            else if((x1+y1)%2==0) white+=sw/2,black-=sw/2;

            if(sb%2==0) white-=sb/2,black+=sb/2;
            else if((x3+y3)%2==0) white-=sb/2+1,black+=sb/2+1;
            else if((x3+y3)%2) white-=sb/2,black+=sb/2;
        }
        /*else if(x3<x1&&y3<y1&&x4>x2&&y4>y2) //
        {
            if(sb%2==0) white-=sb/2,black+=sb/2;
            else if((x3+y3)%2==0) white-=sb/2+1,black+=sb/2+1;
            else if((x3+y3)%2) white-=sb/2,black+=sb/2;
        }*/
        else //
        {
            long long x5=max(x1,x3),y5=max(y1,y3);
            long long x6=min(x2,x4),y6=min(y2,y4);
            long long sl = (x6-x5+1)*(y6-y5+1);

            //cout<<"sw:"<<sw<<" sb:"<<sb<<" sl:"<<sl<<endl;
            if(sw%2==0) white+=sw/2,black-=sw/2;
            else if((x1+y1)%2) white+=sw/2+1,black-=sw/2+1;
            else if((x1+y1)%2==0) white+=sw/2,black-=sw/2;
            //cout<<"white: "<<white<<" black:"<<black<<endl;
            if(sb%2==0) white-=sb/2,black+=sb/2;
            else if((x3+y3)%2==0) white-=sb/2+1,black+=sb/2+1;
            else if((x3+y3)%2) white-=sb/2,black+=sb/2;

            if(sl%2==0) white-=sl/2,black+=sl/2;
            else if((x5+y5)%2) white-=sl/2+1,black+=sl/2+1;
            else if((x5+y5)%2==0) white-=sl/2,black+=sl/2;
        }
        cout<<white<<" "<<black<<endl;
    }
}