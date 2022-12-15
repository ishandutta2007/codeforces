/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/
void increment(int &i,int &j,int m)
{
            if(j==m && i%2==1)
        {
            i++;
        }
        else if(j==1 && i%2==0)
        {
            i++;
        }
        else if(i%2==1)
        {
            j++;
        }
        else
        {
            j--;
        }
}

#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    int i=1,j=1;
    while(k>1)
    {
        cout<<"2 "<<i<<" "<<j<<" ";
        increment(i,j,m);
        cout<<i<<" "<<j<<endl;
        increment(i,j,m);
        k--;
    }
    if(i%2==1)
    {
        cout<<(n-i)*m + (m-j)+1<<" ";
    }
    else
    {
        cout<<(n-i)*m + j<<" ";
    }
    while(true)
    {
        cout<<i<<" "<<j<<" ";
        increment(i,j,m);
        if(i>n)
        {
            break;
        }
    }
    return 0;
}