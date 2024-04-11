#include<iostream>
#include<set>
using namespace std;

int main()

{
    int a,b,c;
    set<int> s;
    cin>>a>>b>>c;
    int number=0,counter=0;
    
    while(true)
    {
    counter++;
    number = 10*a/b;
    //cout<<a<<" "<<b<<" "<<number<<endl;
    a = 10*a-(10*a/b)*b;
    if(number==c)
    {
        cout<<counter;
        break;
    }
    if(s.count(a)!=0)
    {
        cout<<"-1";
        break;
    }
    s.insert(a);
    }
    return 0;
}