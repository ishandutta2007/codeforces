#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M[5][5];
    int I, J;
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
        {
            cin>>M[i][j];
            if(M[i][j]==1)
            {
                I=i;
                J=j;
            }
        }
    cout<<abs(I-2)+abs(J-2);
    return 0;
}