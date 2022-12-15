/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int answer=10;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int counter=0;
        while(counter!=10)
        {
            answer+=9;
            counter=0;
            long long int z=answer;
            while(z!=0)
            {
                counter+=(z%10);
                z=z/10;
            }
        }
    }
    cout<<answer;
    return 0;
}