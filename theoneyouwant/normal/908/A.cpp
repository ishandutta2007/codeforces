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
    
    char s;
    int number=0;
    while(cin>>s)
    {
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='1'||s=='3'||s=='5'||s=='7'||s=='9')
        {
            number++;
        }
    }
    cout<<number;
     return 0;
}