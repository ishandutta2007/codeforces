#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int W,H;
    cin>>W>>H;
    string img[H];
    for(int h=0;h<H;h++)
        cin>>img[h];
    for(int w=0;w<W;w++)
        for(int i=0;i<2;i++)
        {
            for(int h=0;h<H;h++)
                cout<<img[h][w]<<img[h][w];
            cout<<endl;
        }
}