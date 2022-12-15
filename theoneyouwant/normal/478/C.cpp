#include <iostream>
using namespace std;

void order(long long int &a,long long int &b,long long int &c)
{
    long long int f,d,e;
    if(a>=b && a>=c)
    {
        f=a;
        if(b>c)
        {
            d=b;
            e=c;
        }
        else
        {
            d=c;
            e=b;
        }
    }
    else if(b>=a && b>=c)
    {
        f=b;
        if(a>c)
        {
            d=a;
            e=c;
        }
        else
        {
            d=c;
            e=a;
        }
    }
    else if(c>=b && c>=a)
    {
        f=c;
        if(b>a)
        {
            d=b;
            e=a;
        }
        else
        {
            d=a;
            e=b;
        }
    }
    a=f;
    b=d;
    c=e;
}

int main() {
	// your code goes here
	long long int r,g,b;
	cin>>r>>g>>b;
	order(r,g,b);
	if(r>=2*g+2*b)
	{
	    cout<<b+g;
	}
	else
	{
	    cout<<(r+b+g)/3;
	}
	return 0;
}