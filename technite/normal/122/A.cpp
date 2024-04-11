#include <iostream>
using namespace std;
main()
{
    int l;
    cin>>l;
    cout<<(l%4==0||l%7==0||l%47==0||l%74==0||l%477==0 ? "YES":"NO");
}