/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int no=0;
    long double n;
    long long int x;
    cin>>n;
    x=n;
    long double a[x];
    long double sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    long double average;
    average = sum/n;
    sort(a,a+x);
    int i=0;
    while((average-4.5)<-0.00000001)
    {
        no++;
        average = (n*average + 5-a[i])/n;
        i++;
    }
    cout<<no;
     return 0;
}