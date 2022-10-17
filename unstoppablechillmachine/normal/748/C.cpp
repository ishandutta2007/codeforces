#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ll long long
#define ld long double

int n,fx,fy,nx,ny,nsum,sum;
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>s;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='R')
        {
            if (nsum+1>abs(fy-ny)+abs(fx-nx-1))
            {
                sum++;
                nsum=0;
                fy=ny;
                fx=nx;
                //cout<<fy<<" "<<fx<<endl;
            }
            else nsum++;
            nx++;
        }

        if (s[i]=='L')
        {
            if (nsum+1>abs(fy-ny)+abs(fx-nx+1))
            {
                sum++;
                nsum=0;
                fy=ny;
                fx=nx;
                //cout<<fy<<" "<<fx<<endl;
            }
            else nsum++;
            nx--;
        }

        if (s[i]=='U')
        {
            if (nsum+1>abs(fy-ny-1)+abs(fx-nx))
            {
                sum++;
                nsum=0;
                fy=ny;
                fx=nx;
                //cout<<fy<<" "<<fx<<endl;
            }
            else nsum++;
            ny++;
        }

        if (s[i]=='D')
        {
            if (nsum+1>abs(fy-ny+1)+abs(fx-nx))
            {
                sum++;
                nsum=0;
                fy=ny;
                fx=nx;
                //cout<<fy<<" "<<fx<<endl;
            }
            else nsum++;
            ny--;
        }
    }

    cout<<sum+1;


    return 0;
}